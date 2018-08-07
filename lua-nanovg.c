#ifdef __GNUC__
# define LB_API static __attribute__((unused))
#else
# define LB_API static
#endif
#define LBIND_IMPLEMENTATION
#include "lbind.h"

#define LOADGL_STATIC_API
#ifdef __APPLE__
#include "gl_2_0_core.h"
static int opengl_loaded = 0;

#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg/src/nanovg.h"
#include "nanovg/src/nanovg_gl.h"
#undef NANOVG_GL2_IMPLEMENTATION

#define CONTEXT_NEW    nvgCreateGL2
#define CONTEXT_DELETE nvgDeleteGL2

#else
#include "gles2.h"
static int opengl_loaded = 0;

#define NANOVG_GLES2_IMPLEMENTATION
#include "nanovg/src/nanovg.h"
#include "nanovg/src/nanovg_gl.h"
#undef NANOVG_GLES2_IMPLEMENTATION

#define CONTEXT_NEW    nvgCreateGLES2
#define CONTEXT_DELETE nvgDeleteGLES2
#endif

#define NANOSVG_IMPLEMENTATION
#include "nanosvg/src/nanosvg.h"
#define NANOSVGRAST_IMPLEMENTATION
#include "nanosvg/src/nanosvgrast.h"

LBIND_TYPE(lbT_Context, "NanoVG.Context");
LBIND_TYPE(lbT_Image,   "NanoVG.Image");
LBIND_TYPE(lbT_Paint,   "NanoVG.Paint");


/* object creation */

typedef struct LNVGimage LNVGimage;

static NVGcolor check_color(lua_State *L, int idx);
static int test_color(lua_State *L, int idx, NVGcolor *color);
static int test_paint(lua_State *L, int idx, NVGpaint *paint);
static int opentype_image(lua_State *L);

#define check_context(L, idx) ((NVGcontext*)lbind_check((L),(idx),&lbT_Context))
#define check_image(L, idx)   ((LNVGimage*)lbind_check((L),(idx),&lbT_Image))

static int Lnew(lua_State *L) {
    static lbind_EnumItem opts[] = {
        { "aa", NVG_ANTIALIAS },
        { "antialias", NVG_ANTIALIAS },
        { "ss", NVG_STENCIL_STROKES },
        { "stencil_strokes", NVG_STENCIL_STROKES },
        { NULL, 0 }
    };
    static lbind_Enum et = LBIND_INITENUM("CreateFlags", opts);
    int flags;
    NVGcontext *ctx;
    if (!opengl_loaded) {
        if (!loadgl_Init())
            return luaL_error(L, "OpenGL API load failure");
        opengl_loaded = 1;
    }
    flags = lbind_optmask(L, 1, 0, &et);
    ctx = CONTEXT_NEW(flags);
    lbind_wrap(L, ctx, &lbT_Context);
    return 1;
}

static int L__gc(lua_State *L) {
    NVGcontext *ctx = (NVGcontext*)lbind_test(L, 1, &lbT_Context);
    if (ctx != NULL) {
        CONTEXT_DELETE(ctx);
        lbind_delete(L, 1);
    }
    return 0;
}

static NVGpaint *new_paint(lua_State *L, NVGpaint *paint) {
    NVGpaint *p = (NVGpaint*)lbind_new(L, sizeof(NVGpaint), &lbT_Paint);
    *p = *paint;
    return p;
}

static int Lfont(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    const char *name = luaL_checkstring(L, 2);
    const char *filename = luaL_checkstring(L, 3);
    int font = nvgCreateFont(ctx, name, filename);
    if (font < 0)
        lbind_argferror(L, 3, "invalid font file: %s", filename);
    lua_pushinteger(L, font);
    return 1;
}

static int LlinearGradient(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float sx = (float)luaL_checknumber(L, 2);
    float sy = (float)luaL_checknumber(L, 3);
    float ex = (float)luaL_checknumber(L, 4);
    float ey = (float)luaL_checknumber(L, 5);
    NVGcolor icol = check_color(L, 6);
    NVGcolor ocol = check_color(L, 7);
    NVGpaint paint = nvgLinearGradient(ctx, sx, sy, ex, ey, icol, ocol);
    new_paint(L, &paint);
    return 1;
}

static int LboxGradient(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    float w = (float)luaL_checknumber(L, 4);
    float h = (float)luaL_checknumber(L, 5);
    float r = (float)luaL_checknumber(L, 6);
    float f = (float)luaL_checknumber(L, 7);
    NVGcolor icol = check_color(L, 8);
    NVGcolor ocol = check_color(L, 9);
    NVGpaint paint = nvgBoxGradient(ctx, x, y, w, h, r, f, icol, ocol);
    new_paint(L, &paint);
    return 1;
}

static int LradialGradient(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float cx = (float)luaL_checknumber(L, 2);
    float cy = (float)luaL_checknumber(L, 3);
    float inr = (float)luaL_checknumber(L, 4);
    float outr = (float)luaL_checknumber(L, 5);
    NVGcolor icol = check_color(L, 6);
    NVGcolor ocol = check_color(L, 7);
    NVGpaint paint = nvgRadialGradient(ctx, cx, cy, inr, outr, icol, ocol);
    new_paint(L, &paint);
    return 1;
}

/* state routines */

static int Lclear(lua_State *L) {
    NVGcolor c = check_color(L, -1);
    glClearColor(c.r, c.g, c.b, c.r);
    glClear(GL_COLOR_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    lbind_returnself(L);
}

static int LbeginFrame(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    GLsizei w = (GLsizei)luaL_checkinteger(L, 2);
    GLsizei h = (GLsizei)luaL_checkinteger(L, 3);
    float ratio = (float)luaL_optnumber(L, 4, 1.0);
    glViewport(0, 0, w*ratio, h*ratio);
    nvgBeginFrame(ctx, w, h, ratio);
    lbind_returnself(L);
}

static int LcancelFrame(lua_State *L) {
    nvgCancelFrame(check_context(L, 1));
    lbind_returnself(L);
}

static int LendFrame(lua_State *L) {
    nvgEndFrame(check_context(L, 1));
    lbind_returnself(L);
}

static int Lsave(lua_State *L) {
    nvgSave(check_context(L, 1));
    lbind_returnself(L);
}

static int Lrestore(lua_State *L) {
    nvgRestore(check_context(L, 1));
    lbind_returnself(L);
}

static int Lreset(lua_State *L) {
    nvgReset(check_context(L, 1));
    lbind_returnself(L);
}

/* transform routines */

static int LresetTransform(lua_State *L) {
    nvgResetTransform(check_context(L, 1));
    lbind_returnself(L);
}

static int LcurrentTransform(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float d[6];
    nvgCurrentTransform(ctx, d);
    lua_pushnumber(L, d[0]);
    lua_pushnumber(L, d[3]);
    lua_pushnumber(L, d[1]);
    lua_pushnumber(L, d[4]);
    lua_pushnumber(L, d[2]);
    lua_pushnumber(L, d[5]);
    return 6;
}

static int Ltransform(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float a = (float)luaL_optnumber(L, 2, 1.0);
    float b = (float)luaL_optnumber(L, 3, 0.0);
    float c = (float)luaL_optnumber(L, 4, 0.0);
    float d = (float)luaL_optnumber(L, 5, 0.0);
    float e = (float)luaL_optnumber(L, 6, 1.0);
    float f = (float)luaL_optnumber(L, 7, 0.0);
    nvgTransform(ctx, a, b, c, d, e, f);
    lbind_returnself(L);
}

static int Ltranslate(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    nvgTranslate(ctx, x, y);
    lbind_returnself(L);
}

static int Lscale(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    nvgScale(ctx, x, y);
    lbind_returnself(L);
}

static int Lrotate(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float angle = (float)luaL_checknumber(L, 2);
    nvgRotate(ctx, angle);
    lbind_returnself(L);
}

static int Lskew(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_optnumber(L, 2, 0.0);
    float y = (float)luaL_optnumber(L, 3, 0.0);
    if (x != 0.0) nvgSkewX(ctx, x);
    if (y != 0.0) nvgSkewY(ctx, y);
    lbind_returnself(L);
}

/* scissor support */

static int LresetScissor(lua_State *L) {
    nvgResetScissor(check_context(L, 1));
    lbind_returnself(L);
}

static int Lscissor(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    float w = (float)luaL_checknumber(L, 4);
    float h = (float)luaL_checknumber(L, 5);
    nvgScissor(ctx, x, y, w, h);
    lbind_returnself(L);
}

static int LintersectScissor(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    float w = (float)luaL_checknumber(L, 4);
    float h = (float)luaL_checknumber(L, 5);
    nvgIntersectScissor(ctx, x, y, w, h);
    lbind_returnself(L);
}

/* composite operation */

static lbind_EnumItem composite_operations[] = {
    { "atop",             NVG_ATOP             },
    { "copy",             NVG_COPY             },
    { "destination_atop", NVG_DESTINATION_ATOP },
    { "destination_in",   NVG_DESTINATION_IN   },
    { "destination_out",  NVG_DESTINATION_OUT  },
    { "destination_over", NVG_DESTINATION_OVER },
    { "ligther",          NVG_LIGHTER          },
    { "source_in",        NVG_SOURCE_IN        },
    { "source_out",       NVG_SOURCE_OUT       },
    { "xor",              NVG_XOR              },
    { "source_over",      NVG_SOURCE_OVER      },
    { NULL, 0 }
};

static lbind_EnumItem blend_factors[] = {
    { "dst_alpha",            NVG_DST_ALPHA            },
    { "dst_color",            NVG_DST_COLOR            },
    { "one",                  NVG_ONE                  },
    { "one_minus_dst_alpha",  NVG_ONE_MINUS_DST_ALPHA  },
    { "one_minus_dst_color",  NVG_ONE_MINUS_DST_COLOR  },
    { "one_minus_src_alpha",  NVG_ONE_MINUS_SRC_ALPHA  },
    { "one_minus_src_color",  NVG_ONE_MINUS_SRC_COLOR  },
    { "src_alpha",            NVG_SRC_ALPHA            },
    { "src_alpha_saturate",   NVG_SRC_ALPHA_SATURATE   },
    { "src_color",            NVG_SRC_COLOR            },
    { "zero",                 NVG_ZERO                 },
    { NULL, 0 }
};

static int LglobalCompositeOperation(lua_State *L) {
    static lbind_Enum et = LBIND_INITENUM("CompositeOperation",
            composite_operations);
    NVGcontext *ctx = check_context(L, 1);
    int op = lbind_checkenum(L, 2, &et);
    nvgGlobalCompositeOperation(ctx, op);
    lbind_returnself(L);
}

static int LglobalCompositeBlendFunc(lua_State *L) {
    static lbind_Enum et = LBIND_INITENUM("BlendFactor", blend_factors);
    NVGcontext *ctx = check_context(L, 1);
    int sfactor = lbind_checkenum(L, 2, &et);
    int dfactor = lbind_checkenum(L, 3, &et);
    nvgGlobalCompositeBlendFunc(ctx, sfactor, dfactor);
    lbind_returnself(L);
}

static int LglobalCompositeBlendFuncSeparate(lua_State *L) {
    static lbind_Enum et = LBIND_INITENUM("BlendFactor", blend_factors);
    NVGcontext *ctx = check_context(L, 1);
    int srcRGB   = lbind_checkenum(L, 2, &et);
    int dstRGB   = lbind_checkenum(L, 3, &et);
    int srcAlpha = lbind_checkenum(L, 4, &et);
    int dstAlpha = lbind_checkenum(L, 5, &et);
    nvgGlobalCompositeBlendFuncSeparate(ctx, srcRGB, dstRGB, srcAlpha, dstAlpha);
    lbind_returnself(L);
}

/* path routines */

static int LbeginPath(lua_State *L) {
    nvgBeginPath(check_context(L, 1));
    lbind_returnself(L);
}

static int LmoveTo(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    nvgMoveTo(ctx, x, y);
    lbind_returnself(L);
}

static int LlineTo(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    nvgLineTo(ctx, x, y);
    lbind_returnself(L);
}

static int LquadraticCurveTo(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float cx = (float)luaL_checknumber(L, 2);
    float cy = (float)luaL_checknumber(L, 3);
    float x = (float)luaL_checknumber(L, 4);
    float y = (float)luaL_checknumber(L, 5);
    nvgQuadTo(ctx, cx, cy, x, y);
    lbind_returnself(L);
}

static int LbezierCurveTo(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float c1x = (float)luaL_checknumber(L, 2);
    float c1y = (float)luaL_checknumber(L, 3);
    float c2x = (float)luaL_checknumber(L, 4);
    float c2y = (float)luaL_checknumber(L, 5);
    float x = (float)luaL_checknumber(L, 6);
    float y = (float)luaL_checknumber(L, 7);
    nvgBezierTo(ctx, c1x, c1y, c2x, c2y, x, y);
    lbind_returnself(L);
}

static int LarcTo(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x1 = (float)luaL_checknumber(L, 2);
    float y1 = (float)luaL_checknumber(L, 3);
    float x2 = (float)luaL_checknumber(L, 4);
    float y2 = (float)luaL_checknumber(L, 5);
    float radius = (float)luaL_checknumber(L, 6);
    nvgArcTo(ctx, x1, y1, x2, y2, radius);
    lbind_returnself(L);
}

static int LclosePath(lua_State *L) {
    nvgClosePath(check_context(L, 1));
    lbind_returnself(L);
}

/* primitive routines */

static int Larc(lua_State *L) {
    static lbind_EnumItem opts[] = {
        { "ccw", NVG_CCW },
        { "cw", NVG_CW },
        { NULL, 0 }
    };
    static lbind_Enum et = LBIND_INITENUM("ArcDirection", opts);
    NVGcontext *ctx = check_context(L, 1);
    float cx = (float)luaL_checknumber(L, 2);
    float cy = (float)luaL_checknumber(L, 3);
    float r = (float)luaL_checknumber(L, 4);
    float a0 = (float)luaL_checknumber(L, 5);
    float a1 = (float)luaL_checknumber(L, 6);
    int dir = lbind_optenum(L, 7, NVG_CCW, &et);
    nvgArc(ctx, cx, cy, r, a0, a1, dir);
    lbind_returnself(L);
}

static int Lrect(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    float w = (float)luaL_checknumber(L, 4);
    float h = (float)luaL_checknumber(L, 5);
    nvgRect(ctx, x, y, w, h);
    lbind_returnself(L);
}

static int LroundedRect(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    float w = (float)luaL_checknumber(L, 4);
    float h = (float)luaL_checknumber(L, 5);
    float r = (float)luaL_checknumber(L, 6);
    if (lua_gettop(L) == 6)
        nvgRoundedRect(ctx, x, y, w, h, r);
    else {
        float r2 = (float)luaL_checknumber(L, 7);
        float r3 = (float)luaL_checknumber(L, 8);
        float r4 = (float)luaL_checknumber(L, 9);
        nvgRoundedRectVarying(ctx, x, y, w, h, r, r2, r3, r4);
    }
    lbind_returnself(L);
}

static int Lellipse(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float cx = (float)luaL_checknumber(L, 2);
    float cy = (float)luaL_checknumber(L, 3);
    float rx = (float)luaL_checknumber(L, 4);
    float ry = (float)luaL_checknumber(L, 5);
    nvgEllipse(ctx, cx, cy, rx, ry);
    lbind_returnself(L);
}

static int Lcircle(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float cx = (float)luaL_checknumber(L, 2);
    float cy = (float)luaL_checknumber(L, 3);
    float r = (float)luaL_checknumber(L, 4);
    nvgCircle(ctx, cx, cy, r);
    lbind_returnself(L);
}

static int Lfill(lua_State *L) {
    nvgFill(check_context(L, 1));
    lbind_returnself(L);
}

static int Lstroke(lua_State *L) {
    nvgStroke(check_context(L, 1));
    lbind_returnself(L);
}

/* text routines */

static size_t posrelat(ptrdiff_t pos, size_t len) {
  if (pos >= 0) return (size_t)pos;
  else if (0u - (size_t)pos > len) return 0;
  else return len - ((size_t)-pos) + 1;
}

static const char *check_text(lua_State *L, int idx, const char **e) {
    size_t len;
    const char *s = luaL_checklstring(L, idx, &len);
    size_t i = posrelat(luaL_optinteger(L, idx+1, 1), len);
    size_t j = posrelat(luaL_optinteger(L, idx+2, -1), len);
    if (i < 1) i = 1;
    if (j > len) j = len;
    if (i <= j) {
        *e = s + j;
        return s + i -1;
    }
    return NULL;
}

static int Ltext(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    float width = 0;
    int text_idx = 4;
    const char *s, *e;
    if (lua_type(L, text_idx) == LUA_TNUMBER) {
        width = (float)luaL_checknumber(L, 4);
        ++text_idx;
    }
    s = check_text(L, text_idx, &e);
    if (s != NULL) {
        if (width == 0)
            nvgText(ctx, x, y, s, e);
        else
            nvgTextBox(ctx, x, y, width, s, e);
    }
    lbind_returnself(L);
}

static int LtextBounds(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    int text_idx = 2;
    float x = 0, y = 0, width = 0, box[4];
    const char *s, *e;
    if (lua_type(L, 2) == LUA_TNUMBER) {
        x = (float)luaL_checknumber(L, 2);
        y = (float)luaL_checknumber(L, 3);
        text_idx = 4;
        if (lua_type(L, 4) == LUA_TNUMBER) {
            width = (float)luaL_checknumber(L, 4);
            text_idx = 5;
        }
    }
    s = check_text(L, text_idx, &e);
    if (s != NULL) {
        int nret = 4;
        if (width != 0)
            nvgTextBoxBounds(ctx, x, y, width, s, e, box);
        else {
            lua_pushnumber(L, nvgTextBounds(ctx, x, y, s, e, box));
            nret = 5;
        }
        lua_pushnumber(L, box[0]);
        lua_pushnumber(L, box[1]);
        lua_pushnumber(L, box[2]);
        lua_pushnumber(L, box[3]);
        return nret;
    }
    return 0;
}

static int LtextMetrics(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float ascender, descender, lineh;
    nvgTextMetrics(ctx, &ascender, &descender, &lineh);
    lua_pushnumber(L, ascender);
    lua_pushnumber(L, descender);
    lua_pushnumber(L, lineh);
    return 3;
}

static int LaddFallbackFont(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    const char *font = luaL_checkstring(L, 2);
    const char *fallback = luaL_checkstring(L, 3);
    nvgAddFallbackFont(ctx, font, fallback);
    return 0;
}

/* context settings */

static int LshapeAntiAlias(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    int enabled = lua_toboolean(L, 3);
    nvgShapeAntiAlias(ctx, enabled);
    return 0;
}

static int LglobalAlpha(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float a = (float)luaL_checknumber(L, 3);
    nvgGlobalAlpha(ctx, a);
    return 0;
}

static int LmiterLimit(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float w = (float)luaL_checknumber(L, 3);
    nvgMiterLimit(ctx, w);
    return 0;
}

static int LlineWidth(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float w = (float)luaL_checknumber(L, 3);
    nvgStrokeWidth(ctx, w);
    return 0;
}

static int LfontFace(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    const char *font = luaL_checkstring(L, 3);
    nvgFontFace(ctx, font);
    return 0;
}

static int LfontSize(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float s = (float)luaL_checknumber(L, 3);
    nvgFontSize(ctx, s);
    return 0;
}

static int LtextLetterSpacing(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float s = (float)luaL_checknumber(L, 3);
    nvgTextLetterSpacing(ctx, s);
    return 0;
}

static int LtextLineHeight(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float s = (float)luaL_checknumber(L, 3);
    nvgTextLineHeight(ctx, s);
    return 0;
}

static int LfontBlur(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    float b = (float)luaL_checknumber(L, 3);
    nvgFontBlur(ctx, b);
    return 0;
}

static int LlineCap(lua_State *L) {
    static const char *opts[] = {
        "butt", "round", "square", NULL
    };
    static int map[] = { NVG_BUTT, NVG_ROUND, NVG_SQUARE };
    NVGcontext *ctx = check_context(L, 1);
    int opt = luaL_checkoption(L, 3, NULL, opts);
    nvgLineCap(ctx, map[opt]);
    return 0;
}

static int LlineJoin(lua_State *L) {
    static const char *opts[] = {
        "round", "bevel", "miter", NULL
    };
    static int map[] = { NVG_ROUND, NVG_BEVEL, NVG_MITER };
    NVGcontext *ctx = check_context(L, 1);
    int opt = luaL_checkoption(L, 3, NULL, opts);
    nvgLineJoin(ctx, map[opt]);
    return 0;
}

static int LpathWinding(lua_State *L) {
    static lbind_EnumItem opts[] = {
        { "ccw",   NVG_CCW },
        { "cw",    NVG_CW },
        { "hole",  NVG_HOLE },
        { "solid", NVG_SOLID },
        { NULL, 0 }
    };
    static lbind_Enum et = LBIND_INITENUM("PathWinding", opts);
    NVGcontext *ctx = check_context(L, 1);
    int opt = lbind_checkenum(L, 3, &et);
    nvgPathWinding(ctx, opt);
    return 0;
}

static int LtextAlign(lua_State *L) {
    static lbind_EnumItem opts[] = {
        { "baseline", NVG_ALIGN_BASELINE },
        { "bottom",   NVG_ALIGN_BOTTOM },
        { "center",   NVG_ALIGN_CENTER },
        { "left",     NVG_ALIGN_LEFT },
        { "middle",   NVG_ALIGN_MIDDLE },
        { "right",    NVG_ALIGN_RIGHT },
        { "top",      NVG_ALIGN_TOP },
        { NULL, 0 }
    };
    static lbind_Enum et = LBIND_INITENUM("Align", opts);
    NVGcontext *ctx = check_context(L, 1);
    int align = lbind_checkmask(L, 3, &et);
    nvgTextAlign(ctx, align);
    return 0;
}

static int LstrokeColor(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    NVGcolor color;
    if (test_color(L, 3, &color))
        nvgStrokeColor(ctx, color);
    else
        lbind_typeerror(L, 3, "color");
    return 0;
}

static int LfillColor(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    NVGcolor color;
    if (test_color(L, 3, &color))
        nvgFillColor(ctx, color);
    else
        lbind_typeerror(L, 3, "color");
    return 0;
}

static int LstrokeStyle(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    NVGpaint paint;
    NVGcolor color;
    if (test_paint(L, 3, &paint))
        nvgStrokePaint(ctx, paint);
    else if (test_color(L, 3, &color))
        nvgStrokeColor(ctx, color);
    else
        lbind_typeerror(L, 3, "image/paint/color");
    return 0;
}

static int LfillStyle(lua_State *L) {
    NVGcontext *ctx = check_context(L, 1);
    NVGcolor color;
    NVGpaint paint;
    if (test_paint(L, 3, &paint))
        nvgFillPaint(ctx, paint);
    else if (test_color(L, 3, &color))
        nvgFillColor(ctx, color);
    else
        lbind_typeerror(L, 3, "image/paint/color");
    return 0;
}

/* register lua routines */

LBLIB_API int luaopen_nvg(lua_State *L) {
    luaL_Reg libs[] = {
#define ENTRY(name) { #name, L##name }
        /* meta-methods */
        ENTRY(__gc),
        /* object creation */
        ENTRY(new),
        ENTRY(font),
        ENTRY(linearGradient),
        ENTRY(boxGradient),
        ENTRY(radialGradient),
        /* state routines */
        ENTRY(clear),
        ENTRY(beginFrame),
        ENTRY(cancelFrame),
        ENTRY(endFrame),
        ENTRY(save),
        ENTRY(restore),
        ENTRY(reset),
        /* transform routines */
        ENTRY(resetTransform),
        ENTRY(currentTransform),
        ENTRY(transform),
        ENTRY(translate),
        ENTRY(scale),
        ENTRY(rotate),
        ENTRY(skew),
        /* scissor support */
        ENTRY(resetScissor),
        ENTRY(scissor),
        ENTRY(intersectScissor),
        /* composite operation */
        ENTRY(globalCompositeOperation),
        ENTRY(globalCompositeBlendFunc),
        ENTRY(globalCompositeBlendFuncSeparate),
        /* path routines */
        ENTRY(beginPath),
        ENTRY(moveTo),
        ENTRY(lineTo),
        ENTRY(quadraticCurveTo),
        ENTRY(bezierCurveTo),
        ENTRY(arcTo),
        ENTRY(closePath),
        /* primitive routines */
        ENTRY(arc),
        ENTRY(rect),
        ENTRY(roundedRect),
        ENTRY(ellipse),
        ENTRY(circle),
        ENTRY(fill),
        ENTRY(stroke),
        /* text routines */
        ENTRY(text),
        ENTRY(textMetrics),
        ENTRY(textBounds),
        ENTRY(addFallbackFont),
#undef  ENTRY
        { NULL, NULL }
    };
    luaL_Reg setters[] = {
#define ENTRY(name) { #name, L##name }
        ENTRY(shapeAntiAlias),
        ENTRY(globalAlpha),
        ENTRY(strokeColor),
        ENTRY(fillColor),
        ENTRY(strokeStyle),
        ENTRY(fillStyle),
        ENTRY(miterLimit),
        ENTRY(lineWidth),
        ENTRY(lineCap),
        ENTRY(lineJoin),
        ENTRY(pathWinding),
        ENTRY(fontFace),
        ENTRY(fontSize),
        ENTRY(fontBlur),
        ENTRY(textAlign),
        ENTRY(textLetterSpacing),
        ENTRY(textLineHeight),
#undef  ENTRY
        { NULL, NULL }
    };
    lbind_newmetatable(L, NULL, &lbT_Paint);
    if (lbind_newmetatable(L, libs, &lbT_Context)) {
        lbind_setmaptable(L, setters, LBIND_NEWINDEX);
        opentype_image(L);
        lua_setfield(L, -2, "image");
    }
    return 1;
}


/* image routines */

struct LNVGimage {
    NVGcontext *ctx;
    float ox, oy, ex, ey, angle, alpha;
    int image;
    int repeat;
};

static NVGpaint image_to_paint(LNVGimage *image) {
    // fprintf(stdout, "converting image `%d` to paint: {ox: %f, oy: %f, ex: %f, ey: %f}\n", image->image, image->ox, image->oy, image->ex, image->ey);
    return nvgImagePattern(image->ctx,
            image->ox, image->oy, image->ex, image->ey,
            image->angle, image->image, image->alpha);
}

static int test_paint(lua_State *L, int idx, NVGpaint *paint) {
    NVGpaint *p;
    LNVGimage *img;
    if ((img = (LNVGimage*)lbind_test(L, idx, &lbT_Image)) != NULL) {
        *paint = image_to_paint(img);
        return 1;
    }
    else if ((p = (NVGpaint*)lbind_test(L, idx, &lbT_Paint)) != NULL) {
        *paint = *p;
        return 1;
    }
    return 0;
}

static int Limage___gc(lua_State *L) {
    LNVGimage *image = (LNVGimage*)lbind_test(L, 1, &lbT_Image);
    if (image != NULL && image->image >= 0) {
        nvgDeleteImage(image->ctx, image->image);
        image->image = -1;
        lbind_delete(L, 1);
    }
    return 0;
}

static LNVGimage *new_image(lua_State *L) {
    LNVGimage *image = (LNVGimage*)lbind_new(L, sizeof(LNVGimage), &lbT_Image);
    image->ctx = NULL;
    image->ox = image->oy = 0.0f;
    image->ex = image->ey = 0.0f;
    image->angle = 0.0f;
    image->alpha = 1.0f;
    image->image = -1;
    image->repeat = 0;
    return image;
}

static lbind_EnumItem image_flags[] = {
    { "flipy",    NVG_IMAGE_FLIPY            },
    { "mipmaps",  NVG_IMAGE_GENERATE_MIPMAPS },
    { "nearest",  NVG_IMAGE_NEAREST          },
    { "premulti", NVG_IMAGE_PREMULTIPLIED    },
    { "repeatx",  NVG_IMAGE_REPEATX          },
    { "repeaty",  NVG_IMAGE_REPEATY          },
    { NULL, 0 }
};

static int Limage_load(lua_State *L) {
    static lbind_Enum lbE_imageflags =
        LBIND_INITENUM("ImageFlags", image_flags);
    LNVGimage *image;
    int hasDpiArg = 0;
    if (lua_gettop(L) == 4) {
        hasDpiArg = 1;
    }
    NVGcontext *ctx = check_context(L, 1);
    const char *filename = luaL_checkstring(L, 2);
    int flags = lbind_optmask(L, 3, 0, &lbE_imageflags);
    float dpi = 96.0f;
    if (hasDpiArg) {
        dpi = luaL_checknumber(L, 4);
    }
    const char *ext = strrchr(filename, '.');
    int imageid = -1;
    // defaults
    float ex = 0.0f;
    float ey = 0.0f;
    if (lbE_stricmp(".svg", ext, 4) == 0) {
        // is SVG
        NSVGrasterizer *rast = nsvgCreateRasterizer();
        if (rast == NULL) {
            return luaL_error(L, "Failed allocating rasterizer");
        }
        NSVGimage *vector = nsvgParseFromFile(filename, "px", dpi);
        if (vector != NULL) {
            int w = (int)vector->width;
            int h = (int)vector->height;
            unsigned char* img = malloc(w * h * 4);
            if (img == NULL) {
                return luaL_error(L, "Failed allocating raster image buffer");
            } else {
                nsvgRasterize(rast, vector, 0,0,1, img, w, h, w*4);
                imageid = nvgCreateImageRGBA(ctx, w, h, flags, img);
                if (imageid > 0) {
                    ex = w;
                    ey = h;
                }
            }
        }
        if (rast != NULL) {
            nsvgDeleteRasterizer(rast);
        }
    } else {
        imageid = nvgCreateImage(ctx, filename, flags);
    }
    if (imageid < 0)
        lbind_argferror(L, 3, "invalid image file: %s", filename);
    image = new_image(L);
    image->image = imageid;
    image->ctx = ctx;
    image->ex = ex;
    image->ey = ey;
    return 1;
}

static int Limage_data(lua_State *L) {
    static lbind_Enum lbE_imageflags =
        LBIND_INITENUM("ImageFlags", image_flags);
    LNVGimage *image;
    NVGcontext *ctx = check_context(L, 1);
    size_t len;
    const char *data = luaL_checklstring(L, 2, &len);
    int flags = lbind_optmask(L, 3, 0, &lbE_imageflags);
    int imageid = nvgCreateImageMem(ctx, flags, (unsigned char*)data, len);
    if (imageid < 0)
        luaL_argerror(L, 3, "invalid image data");
    image = new_image(L);
    image->image = imageid;
    image->ctx = ctx;
    return 1;
}

static int Limage_rgba(lua_State *L) {
    static lbind_Enum lbE_imageflags =
        LBIND_INITENUM("ImageFlags", image_flags);
    LNVGimage *image;
    NVGcontext *ctx = check_context(L, 1);
    int w = luaL_checkinteger(L, 2);
    int h = luaL_checkinteger(L, 3);
    int flags = lbind_optmask(L, 4, 0, &lbE_imageflags);
    const char *data = luaL_checkstring(L, 5);
    int imageid = nvgCreateImageRGBA(ctx, w, h, flags, (unsigned char*)data);
    if (imageid < 0)
        luaL_argerror(L, 3, "invalid image data");
    image = new_image(L);
    image->image = imageid;
    image->ctx = ctx;
    return 1;
}

static int Limage_update(lua_State *L) {
    LNVGimage *image = check_image(L, 1);
    const char *data = luaL_checkstring(L, 2);
    nvgUpdateImage(image->ctx, image->image, (unsigned char*)data);
    lbind_returnself(L);
}

static int Limage_size(lua_State *L) {
    LNVGimage *image = check_image(L, 1);
    int w, h;
    nvgImageSize(image->ctx, image->image, &w, &h);
    lua_pushinteger(L, w);
    lua_pushinteger(L, h);
    return 2;
}

static int Limage_extent(lua_State *L) {
    LNVGimage *image = check_image(L, 1);
    image->ox = (float)luaL_checknumber(L, 2);
    image->oy = (float)luaL_checknumber(L, 3);
    image->ex = (float)luaL_checknumber(L, 4);
    image->ey = (float)luaL_checknumber(L, 5);
    lbind_returnself(L);
}

static int Limage_width(lua_State *L) {
    if (lua_gettop(L) == 3) return 0;
    Limage_size(L);
    lua_pop(L, 1);
    return 1;
}

static int Limage_height(lua_State *L) {
    if (lua_gettop(L) == 3) return 0;
    Limage_size(L);
    return 1;
}

static int Limage_repeat(lua_State *L) {
    LNVGimage *image = check_image(L, 1);
    const char *s;
    if (lua_gettop(L) == 2) return 0;
    s = luaL_checkstring(L, 3);
    if (strcmp(s, "x") == 0)
        image->repeat = NVG_IMAGE_REPEATX;
    else if (strcmp(s, "y") == 0)
        image->repeat = NVG_IMAGE_REPEATY;
    else if (strcmp(s, "xy") == 0 || strcmp(s, "yx") == 0)
        image->repeat = NVG_IMAGE_REPEATX|NVG_IMAGE_REPEATY;
    else
        lbind_argferror(L, 3, "invalid image repeat: %s", s);
    return 0;
}

static int Limage_angle(lua_State *L) {
    LNVGimage *image = check_image(L, 1);
    float angle;
    if (lua_gettop(L) == 2) return 0;
    angle = (float)luaL_checknumber(L, 3);
    image->angle = angle;
    return 0;
}

static int Limage_alpha(lua_State *L) {
    LNVGimage *image = check_image(L, 1);
    float alpha;
    if (lua_gettop(L) == 2) return 0;
    alpha = (float)luaL_checknumber(L, 3);
    image->alpha = alpha;
    return 0;
}

static int opentype_image(lua_State *L) {
    luaL_Reg libs[] = {
#define ENTRY(name) { #name, Limage_##name }
        ENTRY(__gc),
        ENTRY(load),
        ENTRY(data),
        ENTRY(rgba),
        ENTRY(update),
        ENTRY(extent),
#undef  ENTRY
        { NULL, NULL }
    };
    luaL_Reg attrs[] = {
#define ENTRY(name) { #name, Limage_##name }
        ENTRY(width),
        ENTRY(height),
        ENTRY(angle),
        ENTRY(repeat),
        ENTRY(alpha),
#undef  ENTRY
        { NULL, NULL }
    };
    if (lbind_newmetatable(L, libs, &lbT_Image)) {
        lbind_setmaptable(L, attrs, LBIND_INDEX|LBIND_NEWINDEX);
        lbind_setlibcall(L, "load");
    }
    return 1;
}


/* color routines */

static lbind_EnumItem colors[] = {
    { "aliceblue",            0xFFF0F8FF },
    { "antiquewhite",         0xFFFAEBD7 },
    { "aqua",                 0xFF00FFFF },
    { "aquamarine",           0xFF7FFFD4 },
    { "azure",                0xFFF0FFFF },
    { "beige",                0xFFF5F5DC },
    { "bisque",               0xFFFFE4C4 },
    { "black",                0xFF000000 },
    { "blanchedalmond",       0xFFFFEBCD },
    { "blue",                 0xFF0000FF },
    { "blueviolet",           0xFF8A2BE2 },
    { "brown",                0xFFA52A2A },
    { "burlywood",            0xFFDEB887 },
    { "cadetblue",            0xFF5F9EA0 },
    { "chartreuse",           0xFF7FFF00 },
    { "chocolate",            0xFFD2691E },
    { "coral",                0xFFFF7F50 },
    { "cornflowerblue",       0xFF6495ED },
    { "cornsilk",             0xFFFFF8DC },
    { "crimson",              0xFFDC143C },
    { "cyan",                 0xFF00FFFF },
    { "darkblue",             0xFF00008B },
    { "darkcyan",             0xFF008B8B },
    { "darkgoldenrod",        0xFFB8860B },
    { "darkgray",             0xFFA9A9A9 },
    { "darkgreen",            0xFF006400 },
    { "darkkhaki",            0xFFBDB76B },
    { "darkmagenta",          0xFF8B008B },
    { "darkolivegreen",       0xFF556B2F },
    { "darkorange",           0xFFFF8C00 },
    { "darkorchid",           0xFF9932CC },
    { "darkred",              0xFF8B0000 },
    { "darksalmon",           0xFFE9967A },
    { "darkseagreen",         0xFF8FBC8F },
    { "darkslateblue",        0xFF483D8B },
    { "darkslategray",        0xFF2F4F4F },
    { "darkturquoise",        0xFF00CED1 },
    { "darkviolet",           0xFF9400D3 },
    { "deeppink",             0xFFFF1493 },
    { "deepskyblue",          0xFF00BFFF },
    { "dimgray",              0xFF696969 },
    { "dodgerblue",           0xFF1E90FF },
    { "firebrick",            0xFFB22222 },
    { "floralwhite",          0xFFFFFAF0 },
    { "forestgreen",          0xFF228B22 },
    { "fuchsia",              0xFFFF00FF },
    { "gainsboro",            0xFFDCDCDC },
    { "ghostwhite",           0xFFF8F8FF },
    { "gold",                 0xFFFFD700 },
    { "goldenrod",            0xFFDAA520 },
    { "gray",                 0xFF808080 },
    { "green",                0xFF008000 },
    { "greenyellow",          0xFFADFF2F },
    { "honeydew",             0xFFF0FFF0 },
    { "hotpink",              0xFFFF69B4 },
    { "indianred",            0xFFCD5C5C },
    { "indigo",               0xFF4B0082 },
    { "ivory",                0xFFFFFFF0 },
    { "khaki",                0xFFF0E68C },
    { "lavender",             0xFFE6E6FA },
    { "lavenderblush",        0xFFFFF0F5 },
    { "lawngreen",            0xFF7CFC00 },
    { "lemonchiffon",         0xFFFFFACD },
    { "lightblue",            0xFFADD8E6 },
    { "lightcoral",           0xFFF08080 },
    { "lightcyan",            0xFFE0FFFF },
    { "lightgoldenrodYellow", 0xFFFAFAD2 },
    { "lightgray",            0xFFD3D3D3 },
    { "lightgreen",           0xFF90EE90 },
    { "lightpink",            0xFFFFB6C1 },
    { "lightsalmon",          0xFFFFA07A },
    { "lightseagreen",        0xFF20B2AA },
    { "lightskyblue",         0xFF87CEFA },
    { "lightslategray",       0xFF778899 },
    { "lightsteelblue",       0xFFB0C4DE },
    { "lightyellow",          0xFFFFFFE0 },
    { "lime",                 0xFF00FF00 },
    { "limegreen",            0xFF32CD32 },
    { "linen",                0xFFFAF0E6 },
    { "magenta",              0xFFFF00FF },
    { "maroon",               0xFF800000 },
    { "mediumaquamarine",     0xFF66CDAA },
    { "mediumblue",           0xFF0000CD },
    { "mediumorchid",         0xFFBA55D3 },
    { "mediumpurple",         0xFF9370DB },
    { "mediumseagreen",       0xFF3CB371 },
    { "mediumslateblue",      0xFF7B68EE },
    { "mediumspringgreen",    0xFF00FA9A },
    { "mediumturquoise",      0xFF48D1CC },
    { "mediumvioletred",      0xFFC71585 },
    { "midnightblue",         0xFF191970 },
    { "mintcream",            0xFFF5FFFA },
    { "mistyrose",            0xFFFFE4E1 },
    { "moccasin",             0xFFFFE4B5 },
    { "navajowhite",          0xFFFFDEAD },
    { "navy",                 0xFF000080 },
    { "oldlace",              0xFFFDF5E6 },
    { "olive",                0xFF808000 },
    { "olivedrab",            0xFF6B8E23 },
    { "orange",               0xFFFFA500 },
    { "orangered",            0xFFFF4500 },
    { "orchid",               0xFFDA70D6 },
    { "palegoldenrod",        0xFFEEE8AA },
    { "palegreen",            0xFF98FB98 },
    { "paleturquoise",        0xFFAFEEEE },
    { "palevioletred",        0xFFDB7093 },
    { "papayawhip",           0xFFFFEFD5 },
    { "peachpuff",            0xFFFFDAB9 },
    { "peru",                 0xFFCD853F },
    { "pink",                 0xFFFFC0CB },
    { "plum",                 0xFFDDA0DD },
    { "powderblue",           0xFFB0E0E6 },
    { "purple",               0xFF800080 },
    { "red",                  0xFFFF0000 },
    { "rosybrown",            0xFFBC8F8F },
    { "royalblue",            0xFF4169E1 },
    { "saddlebrown",          0xFF8B4513 },
    { "salmon",               0xFFFA8072 },
    { "sandybrown",           0xFFF4A460 },
    { "seagreen",             0xFF2E8B57 },
    { "seashell",             0xFFFFF5EE },
    { "sienna",               0xFFA0522D },
    { "silver",               0xFFC0C0C0 },
    { "skyblue",              0xFF87CEEB },
    { "slateblue",            0xFF6A5ACD },
    { "slategray",            0xFF708090 },
    { "snow",                 0xFFFFFAFA },
    { "springgreen",          0xFF00FF7F },
    { "steelblue",            0xFF4682B4 },
    { "tan",                  0xFFD2B48C },
    { "teal",                 0xFF008080 },
    { "thistle",              0xFFD8BFD8 },
    { "tomato",               0xFFFF6347 },
    { "transparent",          0x00000000 },
    { "turquoise",            0xFF40E0D0 },
    { "violet",               0xFFEE82EE },
    { "wheat",                0xFFF5DEB3 },
    { "white",                0xFFFFFFFF },
    { "whitesmoke",           0xFFF5F5F5 },
    { "yellow",               0xFFFFFF00 },
    { "yellowgreen",          0xFF9ACD32 },
    { NULL, 0 }
};

static NVGcolor unpack_color(unsigned packed) {
    NVGcolor color;
    color.a = ((packed >> 24) & 0xFF)/255.0f;
    color.r = ((packed >> 16) & 0xFF)/255.0f;
    color.g = ((packed >>  8) & 0xFF)/255.0f;
    color.b = ((packed      ) & 0xFF)/255.0f;
    return color;
}

static unsigned pack_color(NVGcolor c) {
    return 
        ((int)(c.a * 255) << 24) |
        ((int)(c.r * 255) << 16) |
        ((int)(c.g * 255) <<  8) |
        ((int)(c.b * 255)      ) ;
}

static int color_from_name(const char *name, size_t len, NVGcolor *c) {
    static lbind_Enum et = LBIND_INITENUM("ColorName", colors);
    lbind_EnumItem *item;
    item = lbind_findenum(&et, name, len);
    if (item == NULL)
        return 0;
    *c = unpack_color(item->value);
    return 1;
}

static const char *skip_whitespace(const char *s) {
    while (*s == '\t' || *s == '\n' || *s == '\r' || *s == ' ')
        ++s;
    return s;
}

static const char *parse_hexadigit(const char *s, unsigned *pv) {
    *pv = 0;
    while ((*s >= '0' && *s <= '9') ||
            (*s >= 'A' && *s <= 'F') ||
            (*s >= 'a' && *s <= 'f')) {
        int ch = *s;
        if (ch <= '9')
            ch -= '0';
        else if (ch <= 'F')
            ch -= 'A' - 10;
        else
            ch -= 'a' - 10;
        *pv = (*pv << 4) | ch;
        ++s;
    }
    return s;
}

static int color_from_hexa(const char *s, size_t len, NVGcolor *c) {
    const char *e;
    unsigned v, packed = 0;
    s = skip_whitespace(s);
    if (*s++ != '#') return 0;
    e = parse_hexadigit(s, &v);
    e = skip_whitespace(e);
    if (*e != '\0') return 0;
    if (len == 4 || len == 5) {
        packed = len == 4 ? 0xFF000000 :
            ((v>>8)&0xF0)|((v>>12)&0xF) << 24;
        packed |=
            ((v>>4)&0xF0)|((v>>8)&0xF) << 16 |
            ((v   )&0xF0)|((v>>4)&0xF) <<  8 |
            ((v<<4)&0xF0)|((v   )&0xF)       ;
    }
    else if (len == 7 || len == 9) {
        packed = v;
        if (len == 7)
            packed |= 0xFF000000;
    }
    *c = unpack_color(packed);
    return 1;
}

static const char *parse_decimal(const char *s, int *pv) {
    *pv = 0;
    s = skip_whitespace(s);
    while (*s >= '0' && *s <= '9') {
        *pv *= 10;
        *pv += *s - '0';
        ++s;
    }
    return skip_whitespace(s);
}

static int color_from_deci(const char *s, size_t len, NVGcolor *c) {
    const char *e;
    int packed = 0, v;
    s = skip_whitespace(s);
    if (memcmp(s, "rgb(", 4) == 0)
        s += 4;
    else if (memcmp(s, "rgba(", 5) == 0)
        s += 5;
    else
        return 0;
    if ((e = parse_decimal(s, &v)) == s || *e != ',') return 0;
    packed |= (v&0xFF) << 16; s = e+1;
    if ((e = parse_decimal(s, &v)) == s || *e != ',') return 0;
    packed |= (v&0xFF) <<  8; s = e+1;
    if ((e = parse_decimal(s, &v)) == s || *e != ',') return 0;
    packed |= (v&0xFF)      ; s = e+1;
    e = parse_decimal(s, &v);
    if (v == 0)
        packed |= 0xFF00000000;
    else
        packed |= (v&0xFF) << 24;
    if (*e != ')') return 0;
    *c = unpack_color(packed);
    return 1;
}

static int test_color(lua_State *L, int idx, NVGcolor *color) {
    int type = lua_type(L, idx);
    if (type == LUA_TNUMBER) {
        *color = unpack_color(lua_tointeger(L, idx));
        if (color->a == 0.0f)
            color->a = 1.0f;
        return 1;
    }
    else if (type == LUA_TSTRING) {
        size_t len;
        const char *s = luaL_checklstring(L, idx, &len);
        if (!color_from_hexa(s, len, color) &&
                !color_from_deci(s, len, color) &&
                !color_from_name(s, len, color))
            return lbind_argferror(L, idx, "invalid color format: %s", s);
        return 1;
    }
    return 0;
}

static NVGcolor check_color(lua_State *L, int idx) {
    NVGcolor color;
    if (!test_color(L, idx, &color))
        lbind_typeerror(L, idx, "color");
    return color;
}

static int push_color(lua_State *L, NVGcolor c) {
    lua_pushinteger(L, pack_color(c));
    return 1;
}

static int Lcolor_parse(lua_State *L) {
    return push_color(L, check_color(L, 1));
}

static int Lcolor_rgb(lua_State *L) {
    float r = (float)luaL_checknumber(L, 1);
    float g = (float)luaL_checknumber(L, 2);
    float b = (float)luaL_checknumber(L, 3);
    float a = (float)luaL_optnumber(L, 4, 1.0f);
    return push_color(L, nvgRGBAf(r, g, b, a));
}

static int Lcolor_rgb8(lua_State *L) {
    int r = (int)luaL_checkinteger(L, 1);
    int g = (int)luaL_checkinteger(L, 2);
    int b = (int)luaL_checkinteger(L, 3);
    int a = (int)luaL_optinteger(L, 4, 255);
    return push_color(L, nvgRGBA(r, g, b, a));
}

static int Lcolor_hsl(lua_State *L) {
    float h = (float)luaL_checknumber(L, 1);
    float s = (float)luaL_checknumber(L, 2);
    float l = (float)luaL_checknumber(L, 3);
    float a = (float)luaL_optnumber(L, 4, 1.0f);
    return push_color(L, nvgHSLA(h, s, l, (int)(a*255)));
}

static int Lcolor_lerp(lua_State *L) {
    NVGcolor c0 = check_color(L, 1);
    NVGcolor c1 = check_color(L, 2);
    float u = (float)luaL_checknumber(L, 3);
    return push_color(L, nvgLerpRGBA(c0, c1, u));
}

static int Lcolor_trans(lua_State *L) {
    NVGcolor c = check_color(L, 1);
    float alpha = (float)luaL_checknumber(L, 2);
    return push_color(L, nvgTransRGBAf(c, alpha));
}

static int Lcolor_torgb(lua_State *L) {
    NVGcolor c = check_color(L, 1);
    lua_pushnumber(L, c.r);
    lua_pushnumber(L, c.g);
    lua_pushnumber(L, c.b);
    lua_pushnumber(L, c.a);
    return 4;
}

static int Lcolor_torgb8(lua_State *L) {
    NVGcolor c = check_color(L, 1);
    lua_pushinteger(L, (int)(c.r * 255));
    lua_pushinteger(L, (int)(c.g * 255));
    lua_pushinteger(L, (int)(c.b * 255));
    lua_pushinteger(L, (int)(c.a * 255));
    return 4;
}

LBLIB_API int luaopen_nvg_color(lua_State *L) {
    luaL_Reg libs[] = {
#define Lcolor_rgba Lcolor_rgb
#define Lcolor_hsla Lcolor_hsl
#define ENTRY(name) { #name, Lcolor_##name }
        ENTRY(parse),
        ENTRY(rgb),
        ENTRY(rgb8),
        ENTRY(rgba),
        ENTRY(hsl),
        ENTRY(hsla),
        ENTRY(lerp),
        ENTRY(trans),
        ENTRY(torgb),
        ENTRY(torgb8),
#undef  ENTRY
        { NULL, NULL }
    };
    luaL_newlib(L, libs);
    return 1;
}

/* win32cc: flags+='-s -O3 -shared' libs+='-lopengl32 -llua53'
 * win32cc: output+='nanovg.def' output='nvg.dll'
 * maccc: flags+='-O3 -bundle -undefined dynamic_lookup'
 * maccc: libs+='libnanovg.a' output='nvg.so' */

