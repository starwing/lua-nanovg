#ifdef __GNUC__
# define LB_API static __attribute__((unused))
#else
# define LB_API static
#endif
#define LBIND_IMPLEMENTATION
#include "lbind.h"


#include <string.h>
#include <GLFW/glfw3.h>


LBIND_TYPE(lbT_Window,  "glfw.Window");
LBIND_TYPE(lbT_Monitor, "glfw.Monitor");
LBIND_TYPE(lbT_Cursor,  "glfw.Cursor");

#define liteq(s, t) (memcmp((s), "" t, sizeof(t)) == 0)


static int check_keycode(lua_State *L, int idx);
static int find_hintcode(lua_State *L, const char *s, size_t len);
static int set_hint(lua_State *L, int hint);

static lua_State *globalL;

/* glfw global routines */

static int Lpoll(lua_State *L) {
    glfwPollEvents();
    return 0;
}

static int Lwait(lua_State *L) {
    glfwWaitEvents();
    return 0;
}

static int Ltime(lua_State *L) {
    if (!lua_isnoneornil(L, 1)) {
        double time = luaL_checknumber(L, 1);
        glfwSetTime(time);
        return 0;
    }
    lua_pushnumber(L, glfwGetTime());
    return 1;
}

static int Lhint(lua_State *L) {
    int type = lua_type(L, 1);
    if (type == LUA_TNUMBER)
        return set_hint(L, lua_tointeger(L, 1));
    else if (type == LUA_TSTRING) {
        size_t len;
        const char *s = luaL_checklstring(L, 1, &len);
        if (liteq(s, "reset")) {
            glfwDefaultWindowHints();
            return 0;
        }
        return set_hint(L, find_hintcode(L, s, len));
    }
    return lbind_typeerror(L, 1, "hint name (string/number)");
}

static void error_cb(int err, const char *msg) {
    if (globalL != NULL) {
        lua_State *L = globalL;
        lua_pushnil(L);
        lua_pushstring(L, msg);
        lua_pushinteger(L, err);
    }
}

static int deinit_glfw(lua_State *L) {
    glfwTerminate();
    return 0;
}

static void init_glfw(lua_State *L) {
    globalL = L;
    glfwSetErrorCallback(error_cb);
    if (!glfwInit()) {
        lua_pop(L, 1);
        lua_pushstring(L, "can not initialize glfw: ");
        lua_replace(L, -3);
        lua_concat(L, 2);
        lua_error(L);
    }
    lua_newuserdata(L, 1);
    lua_pushcfunction(L, deinit_glfw);
    lbind_setmetafield(L, -2, "__gc");
}

static void pushtype_Window(lua_State *L);

LBLIB_API int luaopen_glfw(lua_State *L) {
    luaL_Reg libs[] = {
#define ENTRY(name) { #name, L##name }
        ENTRY(poll),
        ENTRY(wait),
        ENTRY(time),
        ENTRY(hint),
#undef  ENTRY
        { NULL, NULL }
    };
    init_glfw(L);
    luaL_newlib(L, libs);
    pushtype_Window(L);
    lua_setfield(L, -2, "window");
    return 1;
}


/* glfw Window binding */

static int Lwindow(lua_State *L) {
    int width = (int)luaL_checkinteger(L, 1);
    int height = (int)luaL_checkinteger(L, 2);
    const char *title = luaL_checkstring(L, 3);
    GLFWmonitor *mon = (GLFWmonitor*)lbind_opt(L, 4, NULL, &lbT_Monitor);
    GLFWwindow *share = (GLFWwindow*)lbind_opt(L, 5, NULL, &lbT_Window);
    GLFWwindow *win = glfwCreateWindow(width, height, title, mon, share);
    if (win == NULL) return 3;
    lbind_wrap(L, win, &lbT_Window);
    return 1;
}

static int Lwin_delete(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_test(L, 1, &lbT_Window);
    if (win != NULL)
        glfwDestroyWindow(win);
    return 0;
}

static int Lwin_show(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    glfwShowWindow(win);
    lbind_returnself(L);
}

static int Lwin_hide(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    glfwHideWindow(win);
    lbind_returnself(L);
}

static int Lwin_iconify(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    glfwIconifyWindow(win);
    lbind_returnself(L);
}

static int Lwin_restore(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    glfwRestoreWindow(win);
    lbind_returnself(L);
}

static int Lwin_shouldclose(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    lua_pushboolean(L, glfwWindowShouldClose(win));
    return 1;
}

static int Lwin_makecurrent(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    glfwMakeContextCurrent(win);
    lbind_returnself(L);
}

static int Lwin_swapbuffers(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    glfwSwapBuffers(win);
    lbind_returnself(L);
}

static int Lwin_key(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    int keycode = check_keycode(L, 2);
    lua_pushboolean(L, glfwGetKey(win, keycode) == GLFW_PRESS);
    return 1;
}

static int Lwin_cursorpos(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    double mx, my;
    glfwGetCursorPos(win, &mx, &my);
    lua_pushnumber(L, mx);
    lua_pushnumber(L, my);
    return 2;
}

static int Lwin_size(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    int width, height;
    glfwGetWindowSize(win, &width, &height);
    lua_pushinteger(L, width);
    lua_pushinteger(L, height);
    return 2;
}

static int Lwin_fbsize(lua_State *L) {
    GLFWwindow *win = (GLFWwindow*)lbind_check(L, 1, &lbT_Window);
    int width, height;
    glfwGetFramebufferSize(win, &width, &height);
    lua_pushinteger(L, width);
    lua_pushinteger(L, height);
    return 2;
}

static void pushtype_Window(lua_State *L) {
    luaL_Reg libs[] = {
#define ENTRY(name) { #name, Lwin_##name }
        ENTRY(delete),
        ENTRY(show),
        ENTRY(hide),
        ENTRY(iconify),
        ENTRY(restore),
        ENTRY(shouldclose),
        ENTRY(makecurrent),
        ENTRY(swapbuffers),
        ENTRY(key),
        ENTRY(cursorpos),
        ENTRY(size),
        ENTRY(fbsize),
#undef  ENTRY
        { NULL, NULL }
    };
    luaL_Reg accs[] = {
#define ENTRY(name) { #name, L##name }
#undef  ENTRY
        { NULL, NULL }
    };
    if (lbind_newmetatable(L, libs, &lbT_Window)) {
        lbind_setmaptable(L, accs, LBIND_INDEX|LBIND_NEWINDEX);
        lua_pop(L, 1);
    }
    lua_pushcfunction(L, Lwindow);
}


/* glfw symbols */

static lbind_EnumItem keys[] = {
    { "backspace",    GLFW_KEY_BACKSPACE     },
    { "capslock",     GLFW_KEY_CAPS_LOCK     },
    { "delete",       GLFW_KEY_DELETE        },
    { "down",         GLFW_KEY_DOWN          },
    { "end",          GLFW_KEY_END           },
    { "enter",        GLFW_KEY_ENTER         },
    { "esc",          GLFW_KEY_ESCAPE        },
    { "f1",           GLFW_KEY_F1            },
    { "f10",          GLFW_KEY_F10           },
    { "f11",          GLFW_KEY_F11           },
    { "f12",          GLFW_KEY_F12           },
    { "f13",          GLFW_KEY_F13           },
    { "f14",          GLFW_KEY_F14           },
    { "f15",          GLFW_KEY_F15           },
    { "f16",          GLFW_KEY_F16           },
    { "f17",          GLFW_KEY_F17           },
    { "f18",          GLFW_KEY_F18           },
    { "f19",          GLFW_KEY_F19           },
    { "f2",           GLFW_KEY_F2            },
    { "f20",          GLFW_KEY_F20           },
    { "f21",          GLFW_KEY_F21           },
    { "f22",          GLFW_KEY_F22           },
    { "f23",          GLFW_KEY_F23           },
    { "f24",          GLFW_KEY_F24           },
    { "f25",          GLFW_KEY_F25           },
    { "f3",           GLFW_KEY_F3            },
    { "f4",           GLFW_KEY_F4            },
    { "f5",           GLFW_KEY_F5            },
    { "f6",           GLFW_KEY_F6            },
    { "f7",           GLFW_KEY_F7            },
    { "f8",           GLFW_KEY_F8            },
    { "f9",           GLFW_KEY_F9            },
    { "home",         GLFW_KEY_HOME          },
    { "insert",       GLFW_KEY_INSERT        },
    { "kp*",          GLFW_KEY_KP_MULTIPLY   },
    { "kp+",          GLFW_KEY_KP_ADD        },
    { "kp-",          GLFW_KEY_KP_SUBTRACT   },
    { "kp.",          GLFW_KEY_KP_DECIMAL    },
    { "kp/",          GLFW_KEY_KP_DIVIDE     },
    { "kp0",          GLFW_KEY_KP_0          },
    { "kp1",          GLFW_KEY_KP_1          },
    { "kp2",          GLFW_KEY_KP_2          },
    { "kp3",          GLFW_KEY_KP_3          },
    { "kp4",          GLFW_KEY_KP_4          },
    { "kp5",          GLFW_KEY_KP_5          },
    { "kp6",          GLFW_KEY_KP_6          },
    { "kp7",          GLFW_KEY_KP_7          },
    { "kp8",          GLFW_KEY_KP_8          },
    { "kp9",          GLFW_KEY_KP_9          },
    { "kp=",          GLFW_KEY_KP_EQUAL      },
    { "kpenter",      GLFW_KEY_KP_ENTER      },
    { "kpshift",      GLFW_KEY_LEFT_SHIFT    },
    { "lalt",         GLFW_KEY_LEFT_ALT      },
    { "lcontrol",     GLFW_KEY_LEFT_CONTROL  },
    { "left",         GLFW_KEY_LEFT          },
    { "lsuper",       GLFW_KEY_LEFT_SUPER    },
    { "menu",         GLFW_KEY_MENU          },
    { "numlock",      GLFW_KEY_NUM_LOCK      },
    { "pagedown",     GLFW_KEY_PAGE_DOWN     },
    { "pageup",       GLFW_KEY_PAGE_UP       },
    { "pause",        GLFW_KEY_PAUSE         },
    { "printscreen",  GLFW_KEY_PRINT_SCREEN  },
    { "ralt",         GLFW_KEY_RIGHT_ALT     },
    { "rcontrol",     GLFW_KEY_RIGHT_CONTROL },
    { "right",        GLFW_KEY_RIGHT         },
    { "rshift",       GLFW_KEY_RIGHT_SHIFT   },
    { "rsuper",       GLFW_KEY_RIGHT_SUPER   },
    { "scrolllock",   GLFW_KEY_SCROLL_LOCK   },
    { "space",        GLFW_KEY_SPACE         },
    { "tab",          GLFW_KEY_TAB           },
    { "up",           GLFW_KEY_UP            },
    { "world1",       GLFW_KEY_WORLD_1       },
    { "world2",       GLFW_KEY_WORLD_2       },
};

static int check_keycode(lua_State *L, int idx) {
    int type = lua_type(L, idx);
    if (type == LUA_TNUMBER)
        return lua_tointeger(L, idx);
    else if (type == LUA_TSTRING) {
        static lbind_Enum et = LBIND_INITENUM(NULL, keys);
        size_t len;
        const char *s = lua_tolstring(L, idx, &len);
        lbind_EnumItem *item;
        if (len == 1)
            return (int)(unsigned char)*s;
        if ((item = lbind_findenum(&et, s, len)) != NULL)
            return item->value;
        return lbind_argferror(L, idx, "invalid key name: %s", s);
    }
    return lbind_typeerror(L, idx, "key code(number/string)");
}

static lbind_EnumItem hints[] = {
    { "accum_alpha_bits",      GLFW_ACCUM_ALPHA_BITS      },
    { "accum_blue_bits",       GLFW_ACCUM_BLUE_BITS       },
    { "accum_green_bits",      GLFW_ACCUM_GREEN_BITS      },
    { "accum_red_bits",        GLFW_ACCUM_RED_BITS        },
    { "alpha_bits",            GLFW_ALPHA_BITS            },
    { "aux_buffers",           GLFW_AUX_BUFFERS           },
    { "blue_bits",             GLFW_BLUE_BITS             },
    { "client_api",            GLFW_CLIENT_API            },
    { "context_robustness",    GLFW_CONTEXT_ROBUSTNESS    },
    { "context_version",       GLFW_CONTEXT_VERSION_MAJOR },
    { "decorated",             GLFW_DECORATED             },
    { "depth_bits",            GLFW_DEPTH_BITS            },
    { "green_bits",            GLFW_GREEN_BITS            },
    { "opengl_debug_context",  GLFW_OPENGL_DEBUG_CONTEXT  },
    { "opengl_forward_compat", GLFW_OPENGL_FORWARD_COMPAT },
    { "opengl_profile",        GLFW_OPENGL_PROFILE        },
    { "red_bits",              GLFW_RED_BITS              },
    { "refresh_rate",          GLFW_REFRESH_RATE          },
    { "resizable",             GLFW_RESIZABLE             },
    { "samples",               GLFW_SAMPLES               },
    { "srgb_capable",          GLFW_SRGB_CAPABLE          },
    { "stencil_bits",          GLFW_STENCIL_BITS          },
    { "stereo",                GLFW_STEREO                },
    { "visible",               GLFW_VISIBLE               },
};

static int find_hintcode(lua_State *L, const char *s, size_t len) {
    static lbind_Enum et = LBIND_INITENUM(NULL, hints);
    lbind_EnumItem *item;
    if ((item = lbind_findenum(&et, s, len)) != NULL)
        return item->value;
    return lbind_argferror(L, 1, "invalid hint name: %s", s);
}

static int set_hint(lua_State *L, int hint) {
    int value;
    const char *s;
    switch (hint) {
    case GLFW_RESIZABLE:
    case GLFW_VISIBLE:
    case GLFW_DECORATED:
    case GLFW_STEREO:
    case GLFW_SRGB_CAPABLE:
    case GLFW_OPENGL_FORWARD_COMPAT:
    case GLFW_OPENGL_DEBUG_CONTEXT:
        value = lua_toboolean(L, 2);
        break;
    case GLFW_RED_BITS:
    case GLFW_GREEN_BITS:
    case GLFW_BLUE_BITS:
    case GLFW_ALPHA_BITS:
    case GLFW_DEPTH_BITS:
    case GLFW_STENCIL_BITS:
    case GLFW_ACCUM_RED_BITS:
    case GLFW_ACCUM_GREEN_BITS:
    case GLFW_ACCUM_BLUE_BITS:
    case GLFW_ACCUM_ALPHA_BITS:
    case GLFW_AUX_BUFFERS:
    case GLFW_SAMPLES:
    case GLFW_REFRESH_RATE:
        value = (int)luaL_checkinteger(L, 2);
        break;
    case GLFW_CONTEXT_VERSION_MAJOR:
        value = (int)luaL_checkinteger(L, 2);
        if (!lua_isnoneornil(L, 3)) {
            int minor = (int)luaL_checkinteger(L, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
        }
        break;
    case GLFW_CLIENT_API:
        s = luaL_checkstring(L, 2);
        value = liteq(s, "opengl") ? GLFW_OPENGL_API :
                liteq(s, "opengl-es") ? GLFW_OPENGL_ES_API :
                lbind_argferror(L, 2, "invalid client api: %s", s);
        break;
    case GLFW_CONTEXT_ROBUSTNESS:
        s = luaL_checkstring(L, 2);
        value = liteq(s, "no_robustness") ? GLFW_NO_ROBUSTNESS :
                liteq(s, "no_reset") ? GLFW_NO_RESET_NOTIFICATION :
                liteq(s, "lost_context") ? GLFW_LOSE_CONTEXT_ON_RESET :
                lbind_argferror(L, 2, "invalid robustness: %s", s);
        break;
    case GLFW_OPENGL_PROFILE:
        s = luaL_checkstring(L, 2);
        value = liteq(s, "any") ? GLFW_OPENGL_ANY_PROFILE :
                liteq(s, "compat") ? GLFW_OPENGL_COMPAT_PROFILE :
                liteq(s, "core") ? GLFW_OPENGL_CORE_PROFILE :
                lbind_argferror(L, 2, "invalid profile: %s", s);
        break;
    default:
        return lbind_argferror(L, 1, "invalid hint value: %X\n", hint);
    }
    glfwWindowHint(hint, value);
    return 0;
}

/* cc: flags+='-s -O2 -mdll -DLUA_BUILD_AS_DLL'
 * cc: libs+='-lglfw3 -llua53 -lopengl32 -lgdi32'
 * cc: output='glfw.dll' */
