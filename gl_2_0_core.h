#ifndef LOADGL_GL_VERSION_2_0_GENERATED_H
#define LOADGL_GL_VERSION_2_0_GENERATED_H

#define GL_VERSION_2_0 1

#ifdef LOADGL_STATIC_API
# ifndef LOADGL_IMPLEMENTATION
#  define LOADGL_IMPLEMENTATION
# endif
# if __GNUC__
#   define LOADGL_API static __attribute((unused))
# else
#   define LOADGL_API static
# endif
#endif

#if !defined(LOADGL_API) && defined(_WIN32)
# ifdef LOADGL_IMPLEMENTATION
#   define LOADGL_API __declspec(dllexport)
# else
#   define LOADGL_API __declspec(dllimport)
# endif
#endif /* LOADGL_API */

#ifndef LOADGL_API
# define LOADGL_API extern
#endif /* LOADGL_API */

LOADGL_API int loadgl_Init(void);
LOADGL_API int loadgl_LoadedCount(void);
LOADGL_API int loadgl_GetMajorVersion(void);
LOADGL_API int loadgl_GetMinorVersion(void);
LOADGL_API int loadgl_IsVersionGEQ(int major, int minor);


#if defined(__glew_h__) || defined(__GLEW_H__)
# error Attempt to include auto-generated header after including glew.h
#endif
#if defined(__gl_h_) || defined(__GL_H__)
# error Attempt to include auto-generated header after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
# error Attempt to include auto-generated header after including glext.h
#endif
#if defined(__gltypes_h_)
# error Attempt to include auto-generated header after gltypes.h
#endif
#if defined(__gl_ATI_h_)
# error Attempt to include auto-generated header after including glATI.h
#endif

#define __glew_h__
#define __GLEW_H__
#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gltypes_h_
#define __gl_ATI_h_

#if defined(_WIN32) && !defined(APIENTRY) &&\
   !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
# ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN 1
# endif
# include <Windows.h>
#endif

#ifndef APIENTRY
# define APIENTRY
#endif /* APIENTRY */

#ifndef APIENTRYP
# define APIENTRYP APIENTRY *
#endif /* APIENTRYP */

#ifndef GLAPI
# define GLAPI extern
#endif /* GLAPI */

#ifdef __cplusplus
# define GL_NS_BEGIN extern "C" {
# define GL_NS_END   }
#else
# define GL_NS_BEGIN
# define GL_NS_END
#endif /* OpenGL Namespace */


GL_NS_BEGIN


typedef unsigned int            GLenum;
typedef float                   GLfloat;
typedef unsigned char           GLboolean;
typedef int                     GLsizei;
typedef unsigned int            GLuint;
typedef int                     GLint;
typedef char                    GLchar;
typedef unsigned char           GLubyte;
typedef ptrdiff_t               GLsizeiptr;
typedef ptrdiff_t               GLintptr;
typedef unsigned int            GLbitfield;
typedef double                  GLdouble;
typedef signed char             GLbyte;
typedef short                   GLshort;
typedef unsigned short          GLushort;


/* OpenGL types */

typedef void                    GLvoid; /* Not an actual GL type, though used in headers in the past */


typedef float                   GLclampf;
typedef double                  GLclampd;
/* OpenGL enums */

#define GL_DEPTH_BUFFER_BIT     0x00000100
#define GL_STENCIL_BUFFER_BIT   0x00000400
#define GL_COLOR_BUFFER_BIT     0x00004000
#define GL_FALSE                0
#define GL_TRUE                 1
#define GL_POINTS               0x0000
#define GL_LINES                0x0001
#define GL_LINE_LOOP            0x0002
#define GL_LINE_STRIP           0x0003
#define GL_TRIANGLES            0x0004
#define GL_TRIANGLE_STRIP       0x0005
#define GL_TRIANGLE_FAN         0x0006
#define GL_QUADS                0x0007
#define GL_NEVER                0x0200
#define GL_LESS                 0x0201
#define GL_EQUAL                0x0202
#define GL_LEQUAL               0x0203
#define GL_GREATER              0x0204
#define GL_NOTEQUAL             0x0205
#define GL_GEQUAL               0x0206
#define GL_ALWAYS               0x0207
#define GL_ZERO                 0
#define GL_ONE                  1
#define GL_SRC_COLOR            0x0300
#define GL_ONE_MINUS_SRC_COLOR  0x0301
#define GL_SRC_ALPHA            0x0302
#define GL_ONE_MINUS_SRC_ALPHA  0x0303
#define GL_DST_ALPHA            0x0304
#define GL_ONE_MINUS_DST_ALPHA  0x0305
#define GL_DST_COLOR            0x0306
#define GL_ONE_MINUS_DST_COLOR  0x0307
#define GL_SRC_ALPHA_SATURATE   0x0308
#define GL_NONE                 0
#define GL_FRONT_LEFT           0x0400
#define GL_FRONT_RIGHT          0x0401
#define GL_BACK_LEFT            0x0402
#define GL_BACK_RIGHT           0x0403
#define GL_FRONT                0x0404
#define GL_BACK                 0x0405
#define GL_LEFT                 0x0406
#define GL_RIGHT                0x0407
#define GL_FRONT_AND_BACK       0x0408
#define GL_NO_ERROR             0
#define GL_INVALID_ENUM         0x0500
#define GL_INVALID_VALUE        0x0501
#define GL_INVALID_OPERATION    0x0502
#define GL_OUT_OF_MEMORY        0x0505
#define GL_CW                   0x0900
#define GL_CCW                  0x0901
#define GL_POINT_SIZE           0x0B11
#define GL_POINT_SIZE_RANGE     0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH          0x0B20
#define GL_LINE_WIDTH           0x0B21
#define GL_LINE_WIDTH_RANGE     0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_POLYGON_MODE         0x0B40
#define GL_POLYGON_SMOOTH       0x0B41
#define GL_CULL_FACE            0x0B44
#define GL_CULL_FACE_MODE       0x0B45
#define GL_FRONT_FACE           0x0B46
#define GL_DEPTH_RANGE          0x0B70
#define GL_DEPTH_TEST           0x0B71
#define GL_DEPTH_WRITEMASK      0x0B72
#define GL_DEPTH_CLEAR_VALUE    0x0B73
#define GL_DEPTH_FUNC           0x0B74
#define GL_STENCIL_TEST         0x0B90
#define GL_STENCIL_CLEAR_VALUE  0x0B91
#define GL_STENCIL_FUNC         0x0B92
#define GL_STENCIL_VALUE_MASK   0x0B93
#define GL_STENCIL_FAIL         0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF          0x0B97
#define GL_STENCIL_WRITEMASK    0x0B98
#define GL_VIEWPORT             0x0BA2
#define GL_DITHER               0x0BD0
#define GL_BLEND_DST            0x0BE0
#define GL_BLEND_SRC            0x0BE1
#define GL_BLEND                0x0BE2
#define GL_LOGIC_OP_MODE        0x0BF0
#define GL_COLOR_LOGIC_OP       0x0BF2
#define GL_DRAW_BUFFER          0x0C01
#define GL_READ_BUFFER          0x0C02
#define GL_SCISSOR_BOX          0x0C10
#define GL_SCISSOR_TEST         0x0C11
#define GL_COLOR_CLEAR_VALUE    0x0C22
#define GL_COLOR_WRITEMASK      0x0C23
#define GL_DOUBLEBUFFER         0x0C32
#define GL_STEREO               0x0C33
#define GL_LINE_SMOOTH_HINT     0x0C52
#define GL_POLYGON_SMOOTH_HINT  0x0C53
#define GL_UNPACK_SWAP_BYTES    0x0CF0
#define GL_UNPACK_LSB_FIRST     0x0CF1
#define GL_UNPACK_ROW_LENGTH    0x0CF2
#define GL_UNPACK_SKIP_ROWS     0x0CF3
#define GL_UNPACK_SKIP_PIXELS   0x0CF4
#define GL_UNPACK_ALIGNMENT     0x0CF5
#define GL_PACK_SWAP_BYTES      0x0D00
#define GL_PACK_LSB_FIRST       0x0D01
#define GL_PACK_ROW_LENGTH      0x0D02
#define GL_PACK_SKIP_ROWS       0x0D03
#define GL_PACK_SKIP_PIXELS     0x0D04
#define GL_PACK_ALIGNMENT       0x0D05
#define GL_MAX_TEXTURE_SIZE     0x0D33
#define GL_MAX_VIEWPORT_DIMS    0x0D3A
#define GL_SUBPIXEL_BITS        0x0D50
#define GL_TEXTURE_1D           0x0DE0
#define GL_TEXTURE_2D           0x0DE1
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE  0x2A02
#define GL_POLYGON_OFFSET_FILL  0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_1D   0x8068
#define GL_TEXTURE_BINDING_2D   0x8069
#define GL_TEXTURE_WIDTH        0x1000
#define GL_TEXTURE_HEIGHT       0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_RED_SIZE     0x805C
#define GL_TEXTURE_GREEN_SIZE   0x805D
#define GL_TEXTURE_BLUE_SIZE    0x805E
#define GL_TEXTURE_ALPHA_SIZE   0x805F
#define GL_DONT_CARE            0x1100
#define GL_FASTEST              0x1101
#define GL_NICEST               0x1102
#define GL_BYTE                 0x1400
#define GL_UNSIGNED_BYTE        0x1401
#define GL_SHORT                0x1402
#define GL_UNSIGNED_SHORT       0x1403
#define GL_INT                  0x1404
#define GL_UNSIGNED_INT         0x1405
#define GL_FLOAT                0x1406
#define GL_DOUBLE               0x140A
#define GL_STACK_OVERFLOW       0x0503
#define GL_STACK_UNDERFLOW      0x0504
#define GL_CLEAR                0x1500
#define GL_AND                  0x1501
#define GL_AND_REVERSE          0x1502
#define GL_COPY                 0x1503
#define GL_AND_INVERTED         0x1504
#define GL_NOOP                 0x1505
#define GL_XOR                  0x1506
#define GL_OR                   0x1507
#define GL_NOR                  0x1508
#define GL_EQUIV                0x1509
#define GL_INVERT               0x150A
#define GL_OR_REVERSE           0x150B
#define GL_COPY_INVERTED        0x150C
#define GL_OR_INVERTED          0x150D
#define GL_NAND                 0x150E
#define GL_SET                  0x150F
#define GL_TEXTURE              0x1702
#define GL_COLOR                0x1800
#define GL_DEPTH                0x1801
#define GL_STENCIL              0x1802
#define GL_STENCIL_INDEX        0x1901
#define GL_DEPTH_COMPONENT      0x1902
#define GL_RED                  0x1903
#define GL_GREEN                0x1904
#define GL_BLUE                 0x1905
#define GL_ALPHA                0x1906
#define GL_RGB                  0x1907
#define GL_RGBA                 0x1908
#define GL_POINT                0x1B00
#define GL_LINE                 0x1B01
#define GL_FILL                 0x1B02
#define GL_KEEP                 0x1E00
#define GL_REPLACE              0x1E01
#define GL_INCR                 0x1E02
#define GL_DECR                 0x1E03
#define GL_VENDOR               0x1F00
#define GL_RENDERER             0x1F01
#define GL_VERSION              0x1F02
#define GL_EXTENSIONS           0x1F03
#define GL_NEAREST              0x2600
#define GL_LINEAR               0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER   0x2800
#define GL_TEXTURE_MIN_FILTER   0x2801
#define GL_TEXTURE_WRAP_S       0x2802
#define GL_TEXTURE_WRAP_T       0x2803
#define GL_PROXY_TEXTURE_1D     0x8063
#define GL_PROXY_TEXTURE_2D     0x8064
#define GL_REPEAT               0x2901
#define GL_R3_G3_B2             0x2A10
#define GL_RGB4                 0x804F
#define GL_RGB5                 0x8050
#define GL_RGB8                 0x8051
#define GL_RGB10                0x8052
#define GL_RGB12                0x8053
#define GL_RGB16                0x8054
#define GL_RGBA2                0x8055
#define GL_RGBA4                0x8056
#define GL_RGB5_A1              0x8057
#define GL_RGBA8                0x8058
#define GL_RGB10_A2             0x8059
#define GL_RGBA12               0x805A
#define GL_RGBA16               0x805B
#define GL_CURRENT_BIT          0x00000001
#define GL_POINT_BIT            0x00000002
#define GL_LINE_BIT             0x00000004
#define GL_POLYGON_BIT          0x00000008
#define GL_POLYGON_STIPPLE_BIT  0x00000010
#define GL_PIXEL_MODE_BIT       0x00000020
#define GL_LIGHTING_BIT         0x00000040
#define GL_FOG_BIT              0x00000080
#define GL_ACCUM_BUFFER_BIT     0x00000200
#define GL_VIEWPORT_BIT         0x00000800
#define GL_TRANSFORM_BIT        0x00001000
#define GL_ENABLE_BIT           0x00002000
#define GL_HINT_BIT             0x00008000
#define GL_EVAL_BIT             0x00010000
#define GL_LIST_BIT             0x00020000
#define GL_TEXTURE_BIT          0x00040000
#define GL_SCISSOR_BIT          0x00080000
/* Guaranteed to mark all attribute groups at once */
#define GL_ALL_ATTRIB_BITS      0xFFFFFFFF
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_QUAD_STRIP           0x0008
#define GL_POLYGON              0x0009
#define GL_ACCUM                0x0100
#define GL_LOAD                 0x0101
#define GL_RETURN               0x0102
#define GL_MULT                 0x0103
#define GL_ADD                  0x0104
#define GL_AUX0                 0x0409
#define GL_AUX1                 0x040A
#define GL_AUX2                 0x040B
#define GL_AUX3                 0x040C
#define GL_2D                   0x0600
#define GL_3D                   0x0601
#define GL_3D_COLOR             0x0602
#define GL_3D_COLOR_TEXTURE     0x0603
#define GL_4D_COLOR_TEXTURE     0x0604
#define GL_PASS_THROUGH_TOKEN   0x0700
#define GL_POINT_TOKEN          0x0701
#define GL_LINE_TOKEN           0x0702
#define GL_POLYGON_TOKEN        0x0703
#define GL_BITMAP_TOKEN         0x0704
#define GL_DRAW_PIXEL_TOKEN     0x0705
#define GL_COPY_PIXEL_TOKEN     0x0706
#define GL_LINE_RESET_TOKEN     0x0707
#define GL_EXP                  0x0800
#define GL_EXP2                 0x0801
#define GL_COEFF                0x0A00
#define GL_ORDER                0x0A01
#define GL_DOMAIN               0x0A02
#define GL_PIXEL_MAP_I_TO_I     0x0C70
#define GL_PIXEL_MAP_S_TO_S     0x0C71
#define GL_PIXEL_MAP_I_TO_R     0x0C72
#define GL_PIXEL_MAP_I_TO_G     0x0C73
#define GL_PIXEL_MAP_I_TO_B     0x0C74
#define GL_PIXEL_MAP_I_TO_A     0x0C75
#define GL_PIXEL_MAP_R_TO_R     0x0C76
#define GL_PIXEL_MAP_G_TO_G     0x0C77
#define GL_PIXEL_MAP_B_TO_B     0x0C78
#define GL_PIXEL_MAP_A_TO_A     0x0C79
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER  0x8090
#define GL_INDEX_ARRAY_POINTER  0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_CURRENT_COLOR        0x0B00
#define GL_CURRENT_INDEX        0x0B01
#define GL_CURRENT_NORMAL       0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_POINT_SMOOTH         0x0B10
#define GL_LINE_STIPPLE         0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT  0x0B26
#define GL_LIST_MODE            0x0B30
#define GL_MAX_LIST_NESTING     0x0B31
#define GL_LIST_BASE            0x0B32
#define GL_LIST_INDEX           0x0B33
#define GL_POLYGON_STIPPLE      0x0B42
#define GL_EDGE_FLAG            0x0B43
#define GL_LIGHTING             0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_AMBIENT  0x0B53
#define GL_SHADE_MODEL          0x0B54
#define GL_COLOR_MATERIAL_FACE  0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL       0x0B57
#define GL_FOG                  0x0B60
#define GL_FOG_INDEX            0x0B61
#define GL_FOG_DENSITY          0x0B62
#define GL_FOG_START            0x0B63
#define GL_FOG_END              0x0B64
#define GL_FOG_MODE             0x0B65
#define GL_FOG_COLOR            0x0B66
#define GL_ACCUM_CLEAR_VALUE    0x0B80
#define GL_MATRIX_MODE          0x0BA0
#define GL_NORMALIZE            0x0BA1
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH  0x0BA5
#define GL_MODELVIEW_MATRIX     0x0BA6
#define GL_PROJECTION_MATRIX    0x0BA7
#define GL_TEXTURE_MATRIX       0x0BA8
#define GL_ATTRIB_STACK_DEPTH   0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_ALPHA_TEST           0x0BC0
#define GL_ALPHA_TEST_FUNC      0x0BC1
#define GL_ALPHA_TEST_REF       0x0BC2
#define GL_INDEX_LOGIC_OP       0x0BF1
#define GL_LOGIC_OP             0x0BF1
#define GL_AUX_BUFFERS          0x0C00
#define GL_INDEX_CLEAR_VALUE    0x0C20
#define GL_INDEX_WRITEMASK      0x0C21
#define GL_INDEX_MODE           0x0C30
#define GL_RGBA_MODE            0x0C31
#define GL_RENDER_MODE          0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT    0x0C51
#define GL_FOG_HINT             0x0C54
#define GL_TEXTURE_GEN_S        0x0C60
#define GL_TEXTURE_GEN_T        0x0C61
#define GL_TEXTURE_GEN_R        0x0C62
#define GL_TEXTURE_GEN_Q        0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_MAP_COLOR            0x0D10
#define GL_MAP_STENCIL          0x0D11
#define GL_INDEX_SHIFT          0x0D12
#define GL_INDEX_OFFSET         0x0D13
#define GL_RED_SCALE            0x0D14
#define GL_RED_BIAS             0x0D15
#define GL_ZOOM_X               0x0D16
#define GL_ZOOM_Y               0x0D17
#define GL_GREEN_SCALE          0x0D18
#define GL_GREEN_BIAS           0x0D19
#define GL_BLUE_SCALE           0x0D1A
#define GL_BLUE_BIAS            0x0D1B
#define GL_ALPHA_SCALE          0x0D1C
#define GL_ALPHA_BIAS           0x0D1D
#define GL_DEPTH_SCALE          0x0D1E
#define GL_DEPTH_BIAS           0x0D1F
#define GL_MAX_EVAL_ORDER       0x0D30
#define GL_MAX_LIGHTS           0x0D31
#define GL_MAX_CLIP_PLANES      0x0D32
#define GL_MAX_PIXEL_MAP_TABLE  0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_INDEX_BITS           0x0D51
#define GL_RED_BITS             0x0D52
#define GL_GREEN_BITS           0x0D53
#define GL_BLUE_BITS            0x0D54
#define GL_ALPHA_BITS           0x0D55
#define GL_DEPTH_BITS           0x0D56
#define GL_STENCIL_BITS         0x0D57
#define GL_ACCUM_RED_BITS       0x0D58
#define GL_ACCUM_GREEN_BITS     0x0D59
#define GL_ACCUM_BLUE_BITS      0x0D5A
#define GL_ACCUM_ALPHA_BITS     0x0D5B
#define GL_NAME_STACK_DEPTH     0x0D70
#define GL_AUTO_NORMAL          0x0D80
#define GL_MAP1_COLOR_4         0x0D90
#define GL_MAP1_INDEX           0x0D91
#define GL_MAP1_NORMAL          0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3        0x0D97
#define GL_MAP1_VERTEX_4        0x0D98
#define GL_MAP2_COLOR_4         0x0DB0
#define GL_MAP2_INDEX           0x0DB1
#define GL_MAP2_NORMAL          0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3        0x0DB7
#define GL_MAP2_VERTEX_4        0x0DB8
#define GL_MAP1_GRID_DOMAIN     0x0DD0
#define GL_MAP1_GRID_SEGMENTS   0x0DD1
#define GL_MAP2_GRID_DOMAIN     0x0DD2
#define GL_MAP2_GRID_SEGMENTS   0x0DD3
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_VERTEX_ARRAY         0x8074
#define GL_NORMAL_ARRAY         0x8075
#define GL_COLOR_ARRAY          0x8076
#define GL_INDEX_ARRAY          0x8077
#define GL_TEXTURE_COORD_ARRAY  0x8078
#define GL_EDGE_FLAG_ARRAY      0x8079
#define GL_VERTEX_ARRAY_SIZE    0x807A
#define GL_VERTEX_ARRAY_TYPE    0x807B
#define GL_VERTEX_ARRAY_STRIDE  0x807C
#define GL_NORMAL_ARRAY_TYPE    0x807E
#define GL_NORMAL_ARRAY_STRIDE  0x807F
#define GL_COLOR_ARRAY_SIZE     0x8081
#define GL_COLOR_ARRAY_TYPE     0x8082
#define GL_COLOR_ARRAY_STRIDE   0x8083
#define GL_INDEX_ARRAY_TYPE     0x8085
#define GL_INDEX_ARRAY_STRIDE   0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_TEXTURE_COMPONENTS   0x1003
#define GL_TEXTURE_BORDER       0x1005
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_TEXTURE_PRIORITY     0x8066
#define GL_TEXTURE_RESIDENT     0x8067
#define GL_AMBIENT              0x1200
#define GL_DIFFUSE              0x1201
#define GL_SPECULAR             0x1202
#define GL_POSITION             0x1203
#define GL_SPOT_DIRECTION       0x1204
#define GL_SPOT_EXPONENT        0x1205
#define GL_SPOT_CUTOFF          0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION   0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_COMPILE              0x1300
#define GL_COMPILE_AND_EXECUTE  0x1301
#define GL_2_BYTES              0x1407
#define GL_3_BYTES              0x1408
#define GL_4_BYTES              0x1409
#define GL_EMISSION             0x1600
#define GL_SHININESS            0x1601
#define GL_AMBIENT_AND_DIFFUSE  0x1602
#define GL_COLOR_INDEXES        0x1603
#define GL_MODELVIEW            0x1700
#define GL_PROJECTION           0x1701
#define GL_COLOR_INDEX          0x1900
#define GL_LUMINANCE            0x1909
#define GL_LUMINANCE_ALPHA      0x190A
#define GL_BITMAP               0x1A00
#define GL_RENDER               0x1C00
#define GL_FEEDBACK             0x1C01
#define GL_SELECT               0x1C02
#define GL_FLAT                 0x1D00
#define GL_SMOOTH               0x1D01
#define GL_S                    0x2000
#define GL_T                    0x2001
#define GL_R                    0x2002
#define GL_Q                    0x2003
#define GL_MODULATE             0x2100
#define GL_DECAL                0x2101
#define GL_TEXTURE_ENV_MODE     0x2200
#define GL_TEXTURE_ENV_COLOR    0x2201
#define GL_TEXTURE_ENV          0x2300
#define GL_EYE_LINEAR           0x2400
#define GL_OBJECT_LINEAR        0x2401
#define GL_SPHERE_MAP           0x2402
#define GL_TEXTURE_GEN_MODE     0x2500
#define GL_OBJECT_PLANE         0x2501
#define GL_EYE_PLANE            0x2502
#define GL_CLAMP                0x2900
#define GL_ALPHA4               0x803B
#define GL_ALPHA8               0x803C
#define GL_ALPHA12              0x803D
#define GL_ALPHA16              0x803E
#define GL_LUMINANCE4           0x803F
#define GL_LUMINANCE8           0x8040
#define GL_LUMINANCE12          0x8041
#define GL_LUMINANCE16          0x8042
#define GL_LUMINANCE4_ALPHA4    0x8043
#define GL_LUMINANCE6_ALPHA2    0x8044
#define GL_LUMINANCE8_ALPHA8    0x8045
#define GL_LUMINANCE12_ALPHA4   0x8046
#define GL_LUMINANCE12_ALPHA12  0x8047
#define GL_LUMINANCE16_ALPHA16  0x8048
#define GL_INTENSITY            0x8049
#define GL_INTENSITY4           0x804A
#define GL_INTENSITY8           0x804B
#define GL_INTENSITY12          0x804C
#define GL_INTENSITY16          0x804D
#define GL_V2F                  0x2A20
#define GL_V3F                  0x2A21
#define GL_C4UB_V2F             0x2A22
#define GL_C4UB_V3F             0x2A23
#define GL_C3F_V3F              0x2A24
#define GL_N3F_V3F              0x2A25
#define GL_C4F_N3F_V3F          0x2A26
#define GL_T2F_V3F              0x2A27
#define GL_T4F_V4F              0x2A28
#define GL_T2F_C4UB_V3F         0x2A29
#define GL_T2F_C3F_V3F          0x2A2A
#define GL_T2F_N3F_V3F          0x2A2B
#define GL_T2F_C4F_N3F_V3F      0x2A2C
#define GL_T4F_C4F_N3F_V4F      0x2A2D
#define GL_CLIP_PLANE0          0x3000
#define GL_CLIP_PLANE1          0x3001
#define GL_CLIP_PLANE2          0x3002
#define GL_CLIP_PLANE3          0x3003
#define GL_CLIP_PLANE4          0x3004
#define GL_CLIP_PLANE5          0x3005
#define GL_LIGHT0               0x4000
#define GL_LIGHT1               0x4001
#define GL_LIGHT2               0x4002
#define GL_LIGHT3               0x4003
#define GL_LIGHT4               0x4004
#define GL_LIGHT5               0x4005
#define GL_LIGHT6               0x4006
#define GL_LIGHT7               0x4007


#define GL_UNSIGNED_BYTE_3_3_2  0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_TEXTURE_BINDING_3D   0x806A
#define GL_PACK_SKIP_IMAGES     0x806B
#define GL_PACK_IMAGE_HEIGHT    0x806C
#define GL_UNPACK_SKIP_IMAGES   0x806D
#define GL_UNPACK_IMAGE_HEIGHT  0x806E
#define GL_TEXTURE_3D           0x806F
#define GL_PROXY_TEXTURE_3D     0x8070
#define GL_TEXTURE_DEPTH        0x8071
#define GL_TEXTURE_WRAP_R       0x8072
#define GL_MAX_3D_TEXTURE_SIZE  0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_BGR                  0x80E0
#define GL_BGRA                 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE        0x812F
#define GL_TEXTURE_MIN_LOD      0x813A
#define GL_TEXTURE_MAX_LOD      0x813B
#define GL_TEXTURE_BASE_LEVEL   0x813C
#define GL_TEXTURE_MAX_LEVEL    0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_RESCALE_NORMAL       0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR         0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D


#define GL_TEXTURE0             0x84C0
#define GL_TEXTURE1             0x84C1
#define GL_TEXTURE2             0x84C2
#define GL_TEXTURE3             0x84C3
#define GL_TEXTURE4             0x84C4
#define GL_TEXTURE5             0x84C5
#define GL_TEXTURE6             0x84C6
#define GL_TEXTURE7             0x84C7
#define GL_TEXTURE8             0x84C8
#define GL_TEXTURE9             0x84C9
#define GL_TEXTURE10            0x84CA
#define GL_TEXTURE11            0x84CB
#define GL_TEXTURE12            0x84CC
#define GL_TEXTURE13            0x84CD
#define GL_TEXTURE14            0x84CE
#define GL_TEXTURE15            0x84CF
#define GL_TEXTURE16            0x84D0
#define GL_TEXTURE17            0x84D1
#define GL_TEXTURE18            0x84D2
#define GL_TEXTURE19            0x84D3
#define GL_TEXTURE20            0x84D4
#define GL_TEXTURE21            0x84D5
#define GL_TEXTURE22            0x84D6
#define GL_TEXTURE23            0x84D7
#define GL_TEXTURE24            0x84D8
#define GL_TEXTURE25            0x84D9
#define GL_TEXTURE26            0x84DA
#define GL_TEXTURE27            0x84DB
#define GL_TEXTURE28            0x84DC
#define GL_TEXTURE29            0x84DD
#define GL_TEXTURE30            0x84DE
#define GL_TEXTURE31            0x84DF
#define GL_ACTIVE_TEXTURE       0x84E0
#define GL_MULTISAMPLE          0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE  0x809F
#define GL_SAMPLE_COVERAGE      0x80A0
#define GL_SAMPLE_BUFFERS       0x80A8
#define GL_SAMPLES              0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_TEXTURE_CUBE_MAP     0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMPRESSED_RGB       0x84ED
#define GL_COMPRESSED_RGBA      0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED   0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CLAMP_TO_BORDER      0x812D
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS    0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_MULTISAMPLE_BIT      0x20000000
#define GL_NORMAL_MAP           0x8511
#define GL_REFLECTION_MAP       0x8512
#define GL_COMPRESSED_ALPHA     0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMBINE              0x8570
#define GL_COMBINE_RGB          0x8571
#define GL_COMBINE_ALPHA        0x8572
#define GL_SOURCE0_RGB          0x8580
#define GL_SOURCE1_RGB          0x8581
#define GL_SOURCE2_RGB          0x8582
#define GL_SOURCE0_ALPHA        0x8588
#define GL_SOURCE1_ALPHA        0x8589
#define GL_SOURCE2_ALPHA        0x858A
#define GL_OPERAND0_RGB         0x8590
#define GL_OPERAND1_RGB         0x8591
#define GL_OPERAND2_RGB         0x8592
#define GL_OPERAND0_ALPHA       0x8598
#define GL_OPERAND1_ALPHA       0x8599
#define GL_OPERAND2_ALPHA       0x859A
#define GL_RGB_SCALE            0x8573
#define GL_ADD_SIGNED           0x8574
#define GL_INTERPOLATE          0x8575
#define GL_SUBTRACT             0x84E7
#define GL_CONSTANT             0x8576
#define GL_PRIMARY_COLOR        0x8577
#define GL_PREVIOUS             0x8578
#define GL_DOT3_RGB             0x86AE
#define GL_DOT3_RGBA            0x86AF


#define GL_BLEND_DST_RGB        0x80C8
#define GL_BLEND_SRC_RGB        0x80C9
#define GL_BLEND_DST_ALPHA      0x80CA
#define GL_BLEND_SRC_ALPHA      0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_DEPTH_COMPONENT16    0x81A5
#define GL_DEPTH_COMPONENT24    0x81A6
#define GL_DEPTH_COMPONENT32    0x81A7
#define GL_MIRRORED_REPEAT      0x8370
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_LOD_BIAS     0x8501
#define GL_INCR_WRAP            0x8507
#define GL_DECR_WRAP            0x8508
#define GL_TEXTURE_DEPTH_SIZE   0x884A
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_POINT_SIZE_MIN       0x8126
#define GL_POINT_SIZE_MAX       0x8127
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP      0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE       0x8451
#define GL_FRAGMENT_DEPTH       0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM            0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_DEPTH_TEXTURE_MODE   0x884B
#define GL_COMPARE_R_TO_TEXTURE 0x884E


#define GL_FUNC_ADD             0x8006
#define GL_FUNC_SUBTRACT        0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_MIN                  0x8007
#define GL_MAX                  0x8008
#define GL_CONSTANT_COLOR       0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA       0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004


#define GL_BUFFER_SIZE          0x8764
#define GL_BUFFER_USAGE         0x8765
#define GL_QUERY_COUNTER_BITS   0x8864
#define GL_CURRENT_QUERY        0x8865
#define GL_QUERY_RESULT         0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER         0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY            0x88B8
#define GL_WRITE_ONLY           0x88B9
#define GL_READ_WRITE           0x88BA
#define GL_BUFFER_ACCESS        0x88BB
#define GL_BUFFER_MAPPED        0x88BC
#define GL_BUFFER_MAP_POINTER   0x88BD
#define GL_STREAM_DRAW          0x88E0
#define GL_STREAM_READ          0x88E1
#define GL_STREAM_COPY          0x88E2
#define GL_STATIC_DRAW          0x88E4
#define GL_STATIC_READ          0x88E5
#define GL_STATIC_COPY          0x88E6
#define GL_DYNAMIC_DRAW         0x88E8
#define GL_DYNAMIC_READ         0x88E9
#define GL_DYNAMIC_COPY         0x88EA
#define GL_SAMPLES_PASSED       0x8914
#define GL_SRC1_ALPHA           0x8589
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_FOG_COORD_SRC        0x8450
#define GL_FOG_COORD            0x8451
#define GL_CURRENT_FOG_COORD    0x8453
#define GL_FOG_COORD_ARRAY_TYPE 0x8454
#define GL_FOG_COORD_ARRAY_STRIDE 0x8455
#define GL_FOG_COORD_ARRAY_POINTER 0x8456
#define GL_FOG_COORD_ARRAY      0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_SRC0_RGB             0x8580
#define GL_SRC1_RGB             0x8581
#define GL_SRC2_RGB             0x8582
#define GL_SRC0_ALPHA           0x8588
#define GL_SRC2_ALPHA           0x858A


#define GL_BLEND_EQUATION_RGB   0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC    0x8800
#define GL_STENCIL_BACK_FAIL    0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS     0x8824
#define GL_DRAW_BUFFER0         0x8825
#define GL_DRAW_BUFFER1         0x8826
#define GL_DRAW_BUFFER2         0x8827
#define GL_DRAW_BUFFER3         0x8828
#define GL_DRAW_BUFFER4         0x8829
#define GL_DRAW_BUFFER5         0x882A
#define GL_DRAW_BUFFER6         0x882B
#define GL_DRAW_BUFFER7         0x882C
#define GL_DRAW_BUFFER8         0x882D
#define GL_DRAW_BUFFER9         0x882E
#define GL_DRAW_BUFFER10        0x882F
#define GL_DRAW_BUFFER11        0x8830
#define GL_DRAW_BUFFER12        0x8831
#define GL_DRAW_BUFFER13        0x8832
#define GL_DRAW_BUFFER14        0x8833
#define GL_DRAW_BUFFER15        0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_MAX_VERTEX_ATTRIBS   0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER      0x8B30
#define GL_VERTEX_SHADER        0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS   0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE          0x8B4F
#define GL_FLOAT_VEC2           0x8B50
#define GL_FLOAT_VEC3           0x8B51
#define GL_FLOAT_VEC4           0x8B52
#define GL_INT_VEC2             0x8B53
#define GL_INT_VEC3             0x8B54
#define GL_INT_VEC4             0x8B55
#define GL_BOOL                 0x8B56
#define GL_BOOL_VEC2            0x8B57
#define GL_BOOL_VEC3            0x8B58
#define GL_BOOL_VEC4            0x8B59
#define GL_FLOAT_MAT2           0x8B5A
#define GL_FLOAT_MAT3           0x8B5B
#define GL_FLOAT_MAT4           0x8B5C
#define GL_SAMPLER_1D           0x8B5D
#define GL_SAMPLER_2D           0x8B5E
#define GL_SAMPLER_3D           0x8B5F
#define GL_SAMPLER_CUBE         0x8B60
#define GL_SAMPLER_1D_SHADOW    0x8B61
#define GL_SAMPLER_2D_SHADOW    0x8B62
#define GL_DELETE_STATUS        0x8B80
#define GL_COMPILE_STATUS       0x8B81
#define GL_LINK_STATUS          0x8B82
#define GL_VALIDATE_STATUS      0x8B83
#define GL_INFO_LOG_LENGTH      0x8B84
#define GL_ATTACHED_SHADERS     0x8B85
#define GL_ACTIVE_UNIFORMS      0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES    0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM      0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT           0x8CA1
#define GL_UPPER_LEFT           0x8CA2
#define GL_STENCIL_BACK_REF     0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_POINT_SPRITE         0x8861
#define GL_COORD_REPLACE        0x8862
#define GL_MAX_TEXTURE_COORDS   0x8871


/* OpenGL commands */

#define LOADGL_COMMAND_COUNT 545

typedef union LoadGLapis {
  void (APIENTRYP arr[LOADGL_COMMAND_COUNT]) (void);
  struct {
    void (APIENTRYP glCullFace_) (GLenum mode);
    void (APIENTRYP glFrontFace_) (GLenum mode);
    void (APIENTRYP glHint_) (GLenum target, GLenum mode);
    void (APIENTRYP glLineWidth_) (GLfloat width);
    void (APIENTRYP glPointSize_) (GLfloat size);
    void (APIENTRYP glPolygonMode_) (GLenum face, GLenum mode);
    void (APIENTRYP glScissor_) (GLint x, GLint y, GLsizei width, GLsizei height);
    void (APIENTRYP glTexParameterf_) (GLenum target, GLenum pname, GLfloat param);
    void (APIENTRYP glTexParameterfv_) (GLenum target, GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glTexParameteri_) (GLenum target, GLenum pname, GLint param);
    void (APIENTRYP glTexParameteriv_) (GLenum target, GLenum pname, const  GLint  * params);
    void (APIENTRYP glTexImage1D_) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glTexImage2D_) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glDrawBuffer_) (GLenum buf);
    void (APIENTRYP glClear_) (GLbitfield mask);
    void (APIENTRYP glClearColor_) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void (APIENTRYP glClearStencil_) (GLint s);
    void (APIENTRYP glClearDepth_) (GLdouble depth);
    void (APIENTRYP glStencilMask_) (GLuint mask);
    void (APIENTRYP glColorMask_) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    void (APIENTRYP glDepthMask_) (GLboolean flag);
    void (APIENTRYP glDisable_) (GLenum cap);
    void (APIENTRYP glEnable_) (GLenum cap);
    void (APIENTRYP glFinish_) (void);
    void (APIENTRYP glFlush_) (void);
    void (APIENTRYP glBlendFunc_) (GLenum sfactor, GLenum dfactor);
    void (APIENTRYP glLogicOp_) (GLenum opcode);
    void (APIENTRYP glStencilFunc_) (GLenum func, GLint ref, GLuint mask);
    void (APIENTRYP glStencilOp_) (GLenum fail, GLenum zfail, GLenum zpass);
    void (APIENTRYP glDepthFunc_) (GLenum func);
    void (APIENTRYP glPixelStoref_) (GLenum pname, GLfloat param);
    void (APIENTRYP glPixelStorei_) (GLenum pname, GLint param);
    void (APIENTRYP glReadBuffer_) (GLenum src);
    void (APIENTRYP glReadPixels_) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
    void (APIENTRYP glGetBooleanv_) (GLenum pname, GLboolean  * data);
    void (APIENTRYP glGetDoublev_) (GLenum pname, GLdouble  * data);
    GLenum (APIENTRYP glGetError_) (void);
    void (APIENTRYP glGetFloatv_) (GLenum pname, GLfloat  * data);
    void (APIENTRYP glGetIntegerv_) (GLenum pname, GLint  * data);
    const GLubyte * (APIENTRYP glGetString_) (GLenum name);
    void (APIENTRYP glGetTexImage_) (GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
    void (APIENTRYP glGetTexParameterfv_) (GLenum target, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetTexParameteriv_) (GLenum target, GLenum pname, GLint  * params);
    void (APIENTRYP glGetTexLevelParameterfv_) (GLenum target, GLint level, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetTexLevelParameteriv_) (GLenum target, GLint level, GLenum pname, GLint  * params);
    GLboolean (APIENTRYP glIsEnabled_) (GLenum cap);
    void (APIENTRYP glDepthRange_) (GLdouble near, GLdouble far);
    void (APIENTRYP glViewport_) (GLint x, GLint y, GLsizei width, GLsizei height);
    void (APIENTRYP glNewList_) (GLuint list, GLenum mode);
    void (APIENTRYP glEndList_) (void);
    void (APIENTRYP glCallList_) (GLuint list);
    void (APIENTRYP glCallLists_) (GLsizei n, GLenum type, const void * lists);
    void (APIENTRYP glDeleteLists_) (GLuint list, GLsizei range);
    GLuint (APIENTRYP glGenLists_) (GLsizei range);
    void (APIENTRYP glListBase_) (GLuint base);
    void (APIENTRYP glBegin_) (GLenum mode);
    void (APIENTRYP glBitmap_) (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const  GLubyte  * bitmap);
    void (APIENTRYP glColor3b_) (GLbyte red, GLbyte green, GLbyte blue);
    void (APIENTRYP glColor3bv_) (const  GLbyte  * v);
    void (APIENTRYP glColor3d_) (GLdouble red, GLdouble green, GLdouble blue);
    void (APIENTRYP glColor3dv_) (const  GLdouble  * v);
    void (APIENTRYP glColor3f_) (GLfloat red, GLfloat green, GLfloat blue);
    void (APIENTRYP glColor3fv_) (const  GLfloat  * v);
    void (APIENTRYP glColor3i_) (GLint red, GLint green, GLint blue);
    void (APIENTRYP glColor3iv_) (const  GLint  * v);
    void (APIENTRYP glColor3s_) (GLshort red, GLshort green, GLshort blue);
    void (APIENTRYP glColor3sv_) (const  GLshort  * v);
    void (APIENTRYP glColor3ub_) (GLubyte red, GLubyte green, GLubyte blue);
    void (APIENTRYP glColor3ubv_) (const  GLubyte  * v);
    void (APIENTRYP glColor3ui_) (GLuint red, GLuint green, GLuint blue);
    void (APIENTRYP glColor3uiv_) (const  GLuint  * v);
    void (APIENTRYP glColor3us_) (GLushort red, GLushort green, GLushort blue);
    void (APIENTRYP glColor3usv_) (const  GLushort  * v);
    void (APIENTRYP glColor4b_) (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
    void (APIENTRYP glColor4bv_) (const  GLbyte  * v);
    void (APIENTRYP glColor4d_) (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
    void (APIENTRYP glColor4dv_) (const  GLdouble  * v);
    void (APIENTRYP glColor4f_) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void (APIENTRYP glColor4fv_) (const  GLfloat  * v);
    void (APIENTRYP glColor4i_) (GLint red, GLint green, GLint blue, GLint alpha);
    void (APIENTRYP glColor4iv_) (const  GLint  * v);
    void (APIENTRYP glColor4s_) (GLshort red, GLshort green, GLshort blue, GLshort alpha);
    void (APIENTRYP glColor4sv_) (const  GLshort  * v);
    void (APIENTRYP glColor4ub_) (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
    void (APIENTRYP glColor4ubv_) (const  GLubyte  * v);
    void (APIENTRYP glColor4ui_) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
    void (APIENTRYP glColor4uiv_) (const  GLuint  * v);
    void (APIENTRYP glColor4us_) (GLushort red, GLushort green, GLushort blue, GLushort alpha);
    void (APIENTRYP glColor4usv_) (const  GLushort  * v);
    void (APIENTRYP glEdgeFlag_) (GLboolean flag);
    void (APIENTRYP glEdgeFlagv_) (const  GLboolean  * flag);
    void (APIENTRYP glEnd_) (void);
    void (APIENTRYP glIndexd_) (GLdouble c);
    void (APIENTRYP glIndexdv_) (const  GLdouble  * c);
    void (APIENTRYP glIndexf_) (GLfloat c);
    void (APIENTRYP glIndexfv_) (const  GLfloat  * c);
    void (APIENTRYP glIndexi_) (GLint c);
    void (APIENTRYP glIndexiv_) (const  GLint  * c);
    void (APIENTRYP glIndexs_) (GLshort c);
    void (APIENTRYP glIndexsv_) (const  GLshort  * c);
    void (APIENTRYP glNormal3b_) (GLbyte nx, GLbyte ny, GLbyte nz);
    void (APIENTRYP glNormal3bv_) (const  GLbyte  * v);
    void (APIENTRYP glNormal3d_) (GLdouble nx, GLdouble ny, GLdouble nz);
    void (APIENTRYP glNormal3dv_) (const  GLdouble  * v);
    void (APIENTRYP glNormal3f_) (GLfloat nx, GLfloat ny, GLfloat nz);
    void (APIENTRYP glNormal3fv_) (const  GLfloat  * v);
    void (APIENTRYP glNormal3i_) (GLint nx, GLint ny, GLint nz);
    void (APIENTRYP glNormal3iv_) (const  GLint  * v);
    void (APIENTRYP glNormal3s_) (GLshort nx, GLshort ny, GLshort nz);
    void (APIENTRYP glNormal3sv_) (const  GLshort  * v);
    void (APIENTRYP glRasterPos2d_) (GLdouble x, GLdouble y);
    void (APIENTRYP glRasterPos2dv_) (const  GLdouble  * v);
    void (APIENTRYP glRasterPos2f_) (GLfloat x, GLfloat y);
    void (APIENTRYP glRasterPos2fv_) (const  GLfloat  * v);
    void (APIENTRYP glRasterPos2i_) (GLint x, GLint y);
    void (APIENTRYP glRasterPos2iv_) (const  GLint  * v);
    void (APIENTRYP glRasterPos2s_) (GLshort x, GLshort y);
    void (APIENTRYP glRasterPos2sv_) (const  GLshort  * v);
    void (APIENTRYP glRasterPos3d_) (GLdouble x, GLdouble y, GLdouble z);
    void (APIENTRYP glRasterPos3dv_) (const  GLdouble  * v);
    void (APIENTRYP glRasterPos3f_) (GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glRasterPos3fv_) (const  GLfloat  * v);
    void (APIENTRYP glRasterPos3i_) (GLint x, GLint y, GLint z);
    void (APIENTRYP glRasterPos3iv_) (const  GLint  * v);
    void (APIENTRYP glRasterPos3s_) (GLshort x, GLshort y, GLshort z);
    void (APIENTRYP glRasterPos3sv_) (const  GLshort  * v);
    void (APIENTRYP glRasterPos4d_) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    void (APIENTRYP glRasterPos4dv_) (const  GLdouble  * v);
    void (APIENTRYP glRasterPos4f_) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void (APIENTRYP glRasterPos4fv_) (const  GLfloat  * v);
    void (APIENTRYP glRasterPos4i_) (GLint x, GLint y, GLint z, GLint w);
    void (APIENTRYP glRasterPos4iv_) (const  GLint  * v);
    void (APIENTRYP glRasterPos4s_) (GLshort x, GLshort y, GLshort z, GLshort w);
    void (APIENTRYP glRasterPos4sv_) (const  GLshort  * v);
    void (APIENTRYP glRectd_) (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
    void (APIENTRYP glRectdv_) (const  GLdouble  * v1, const  GLdouble  * v2);
    void (APIENTRYP glRectf_) (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    void (APIENTRYP glRectfv_) (const  GLfloat  * v1, const  GLfloat  * v2);
    void (APIENTRYP glRecti_) (GLint x1, GLint y1, GLint x2, GLint y2);
    void (APIENTRYP glRectiv_) (const  GLint  * v1, const  GLint  * v2);
    void (APIENTRYP glRects_) (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
    void (APIENTRYP glRectsv_) (const  GLshort  * v1, const  GLshort  * v2);
    void (APIENTRYP glTexCoord1d_) (GLdouble s);
    void (APIENTRYP glTexCoord1dv_) (const  GLdouble  * v);
    void (APIENTRYP glTexCoord1f_) (GLfloat s);
    void (APIENTRYP glTexCoord1fv_) (const  GLfloat  * v);
    void (APIENTRYP glTexCoord1i_) (GLint s);
    void (APIENTRYP glTexCoord1iv_) (const  GLint  * v);
    void (APIENTRYP glTexCoord1s_) (GLshort s);
    void (APIENTRYP glTexCoord1sv_) (const  GLshort  * v);
    void (APIENTRYP glTexCoord2d_) (GLdouble s, GLdouble t);
    void (APIENTRYP glTexCoord2dv_) (const  GLdouble  * v);
    void (APIENTRYP glTexCoord2f_) (GLfloat s, GLfloat t);
    void (APIENTRYP glTexCoord2fv_) (const  GLfloat  * v);
    void (APIENTRYP glTexCoord2i_) (GLint s, GLint t);
    void (APIENTRYP glTexCoord2iv_) (const  GLint  * v);
    void (APIENTRYP glTexCoord2s_) (GLshort s, GLshort t);
    void (APIENTRYP glTexCoord2sv_) (const  GLshort  * v);
    void (APIENTRYP glTexCoord3d_) (GLdouble s, GLdouble t, GLdouble r);
    void (APIENTRYP glTexCoord3dv_) (const  GLdouble  * v);
    void (APIENTRYP glTexCoord3f_) (GLfloat s, GLfloat t, GLfloat r);
    void (APIENTRYP glTexCoord3fv_) (const  GLfloat  * v);
    void (APIENTRYP glTexCoord3i_) (GLint s, GLint t, GLint r);
    void (APIENTRYP glTexCoord3iv_) (const  GLint  * v);
    void (APIENTRYP glTexCoord3s_) (GLshort s, GLshort t, GLshort r);
    void (APIENTRYP glTexCoord3sv_) (const  GLshort  * v);
    void (APIENTRYP glTexCoord4d_) (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
    void (APIENTRYP glTexCoord4dv_) (const  GLdouble  * v);
    void (APIENTRYP glTexCoord4f_) (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    void (APIENTRYP glTexCoord4fv_) (const  GLfloat  * v);
    void (APIENTRYP glTexCoord4i_) (GLint s, GLint t, GLint r, GLint q);
    void (APIENTRYP glTexCoord4iv_) (const  GLint  * v);
    void (APIENTRYP glTexCoord4s_) (GLshort s, GLshort t, GLshort r, GLshort q);
    void (APIENTRYP glTexCoord4sv_) (const  GLshort  * v);
    void (APIENTRYP glVertex2d_) (GLdouble x, GLdouble y);
    void (APIENTRYP glVertex2dv_) (const  GLdouble  * v);
    void (APIENTRYP glVertex2f_) (GLfloat x, GLfloat y);
    void (APIENTRYP glVertex2fv_) (const  GLfloat  * v);
    void (APIENTRYP glVertex2i_) (GLint x, GLint y);
    void (APIENTRYP glVertex2iv_) (const  GLint  * v);
    void (APIENTRYP glVertex2s_) (GLshort x, GLshort y);
    void (APIENTRYP glVertex2sv_) (const  GLshort  * v);
    void (APIENTRYP glVertex3d_) (GLdouble x, GLdouble y, GLdouble z);
    void (APIENTRYP glVertex3dv_) (const  GLdouble  * v);
    void (APIENTRYP glVertex3f_) (GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glVertex3fv_) (const  GLfloat  * v);
    void (APIENTRYP glVertex3i_) (GLint x, GLint y, GLint z);
    void (APIENTRYP glVertex3iv_) (const  GLint  * v);
    void (APIENTRYP glVertex3s_) (GLshort x, GLshort y, GLshort z);
    void (APIENTRYP glVertex3sv_) (const  GLshort  * v);
    void (APIENTRYP glVertex4d_) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    void (APIENTRYP glVertex4dv_) (const  GLdouble  * v);
    void (APIENTRYP glVertex4f_) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void (APIENTRYP glVertex4fv_) (const  GLfloat  * v);
    void (APIENTRYP glVertex4i_) (GLint x, GLint y, GLint z, GLint w);
    void (APIENTRYP glVertex4iv_) (const  GLint  * v);
    void (APIENTRYP glVertex4s_) (GLshort x, GLshort y, GLshort z, GLshort w);
    void (APIENTRYP glVertex4sv_) (const  GLshort  * v);
    void (APIENTRYP glClipPlane_) (GLenum plane, const  GLdouble  * equation);
    void (APIENTRYP glColorMaterial_) (GLenum face, GLenum mode);
    void (APIENTRYP glFogf_) (GLenum pname, GLfloat param);
    void (APIENTRYP glFogfv_) (GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glFogi_) (GLenum pname, GLint param);
    void (APIENTRYP glFogiv_) (GLenum pname, const  GLint  * params);
    void (APIENTRYP glLightf_) (GLenum light, GLenum pname, GLfloat param);
    void (APIENTRYP glLightfv_) (GLenum light, GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glLighti_) (GLenum light, GLenum pname, GLint param);
    void (APIENTRYP glLightiv_) (GLenum light, GLenum pname, const  GLint  * params);
    void (APIENTRYP glLightModelf_) (GLenum pname, GLfloat param);
    void (APIENTRYP glLightModelfv_) (GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glLightModeli_) (GLenum pname, GLint param);
    void (APIENTRYP glLightModeliv_) (GLenum pname, const  GLint  * params);
    void (APIENTRYP glLineStipple_) (GLint factor, GLushort pattern);
    void (APIENTRYP glMaterialf_) (GLenum face, GLenum pname, GLfloat param);
    void (APIENTRYP glMaterialfv_) (GLenum face, GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glMateriali_) (GLenum face, GLenum pname, GLint param);
    void (APIENTRYP glMaterialiv_) (GLenum face, GLenum pname, const  GLint  * params);
    void (APIENTRYP glPolygonStipple_) (const  GLubyte  * mask);
    void (APIENTRYP glShadeModel_) (GLenum mode);
    void (APIENTRYP glTexEnvf_) (GLenum target, GLenum pname, GLfloat param);
    void (APIENTRYP glTexEnvfv_) (GLenum target, GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glTexEnvi_) (GLenum target, GLenum pname, GLint param);
    void (APIENTRYP glTexEnviv_) (GLenum target, GLenum pname, const  GLint  * params);
    void (APIENTRYP glTexGend_) (GLenum coord, GLenum pname, GLdouble param);
    void (APIENTRYP glTexGendv_) (GLenum coord, GLenum pname, const  GLdouble  * params);
    void (APIENTRYP glTexGenf_) (GLenum coord, GLenum pname, GLfloat param);
    void (APIENTRYP glTexGenfv_) (GLenum coord, GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glTexGeni_) (GLenum coord, GLenum pname, GLint param);
    void (APIENTRYP glTexGeniv_) (GLenum coord, GLenum pname, const  GLint  * params);
    void (APIENTRYP glFeedbackBuffer_) (GLsizei size, GLenum type, GLfloat  * buffer);
    void (APIENTRYP glSelectBuffer_) (GLsizei size, GLuint  * buffer);
    GLint (APIENTRYP glRenderMode_) (GLenum mode);
    void (APIENTRYP glInitNames_) (void);
    void (APIENTRYP glLoadName_) (GLuint name);
    void (APIENTRYP glPassThrough_) (GLfloat token);
    void (APIENTRYP glPopName_) (void);
    void (APIENTRYP glPushName_) (GLuint name);
    void (APIENTRYP glClearAccum_) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void (APIENTRYP glClearIndex_) (GLfloat c);
    void (APIENTRYP glIndexMask_) (GLuint mask);
    void (APIENTRYP glAccum_) (GLenum op, GLfloat value);
    void (APIENTRYP glPopAttrib_) (void);
    void (APIENTRYP glPushAttrib_) (GLbitfield mask);
    void (APIENTRYP glMap1d_) (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const  GLdouble  * points);
    void (APIENTRYP glMap1f_) (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const  GLfloat  * points);
    void (APIENTRYP glMap2d_) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const  GLdouble  * points);
    void (APIENTRYP glMap2f_) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const  GLfloat  * points);
    void (APIENTRYP glMapGrid1d_) (GLint un, GLdouble u1, GLdouble u2);
    void (APIENTRYP glMapGrid1f_) (GLint un, GLfloat u1, GLfloat u2);
    void (APIENTRYP glMapGrid2d_) (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
    void (APIENTRYP glMapGrid2f_) (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
    void (APIENTRYP glEvalCoord1d_) (GLdouble u);
    void (APIENTRYP glEvalCoord1dv_) (const  GLdouble  * u);
    void (APIENTRYP glEvalCoord1f_) (GLfloat u);
    void (APIENTRYP glEvalCoord1fv_) (const  GLfloat  * u);
    void (APIENTRYP glEvalCoord2d_) (GLdouble u, GLdouble v);
    void (APIENTRYP glEvalCoord2dv_) (const  GLdouble  * u);
    void (APIENTRYP glEvalCoord2f_) (GLfloat u, GLfloat v);
    void (APIENTRYP glEvalCoord2fv_) (const  GLfloat  * u);
    void (APIENTRYP glEvalMesh1_) (GLenum mode, GLint i1, GLint i2);
    void (APIENTRYP glEvalPoint1_) (GLint i);
    void (APIENTRYP glEvalMesh2_) (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
    void (APIENTRYP glEvalPoint2_) (GLint i, GLint j);
    void (APIENTRYP glAlphaFunc_) (GLenum func, GLfloat ref);
    void (APIENTRYP glPixelZoom_) (GLfloat xfactor, GLfloat yfactor);
    void (APIENTRYP glPixelTransferf_) (GLenum pname, GLfloat param);
    void (APIENTRYP glPixelTransferi_) (GLenum pname, GLint param);
    void (APIENTRYP glPixelMapfv_) (GLenum map, GLsizei mapsize, const  GLfloat  * values);
    void (APIENTRYP glPixelMapuiv_) (GLenum map, GLsizei mapsize, const  GLuint  * values);
    void (APIENTRYP glPixelMapusv_) (GLenum map, GLsizei mapsize, const  GLushort  * values);
    void (APIENTRYP glCopyPixels_) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
    void (APIENTRYP glDrawPixels_) (GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glGetClipPlane_) (GLenum plane, GLdouble  * equation);
    void (APIENTRYP glGetLightfv_) (GLenum light, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetLightiv_) (GLenum light, GLenum pname, GLint  * params);
    void (APIENTRYP glGetMapdv_) (GLenum target, GLenum query, GLdouble  * v);
    void (APIENTRYP glGetMapfv_) (GLenum target, GLenum query, GLfloat  * v);
    void (APIENTRYP glGetMapiv_) (GLenum target, GLenum query, GLint  * v);
    void (APIENTRYP glGetMaterialfv_) (GLenum face, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetMaterialiv_) (GLenum face, GLenum pname, GLint  * params);
    void (APIENTRYP glGetPixelMapfv_) (GLenum map, GLfloat  * values);
    void (APIENTRYP glGetPixelMapuiv_) (GLenum map, GLuint  * values);
    void (APIENTRYP glGetPixelMapusv_) (GLenum map, GLushort  * values);
    void (APIENTRYP glGetPolygonStipple_) (GLubyte  * mask);
    void (APIENTRYP glGetTexEnvfv_) (GLenum target, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetTexEnviv_) (GLenum target, GLenum pname, GLint  * params);
    void (APIENTRYP glGetTexGendv_) (GLenum coord, GLenum pname, GLdouble  * params);
    void (APIENTRYP glGetTexGenfv_) (GLenum coord, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetTexGeniv_) (GLenum coord, GLenum pname, GLint  * params);
    GLboolean (APIENTRYP glIsList_) (GLuint list);
    void (APIENTRYP glFrustum_) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    void (APIENTRYP glLoadIdentity_) (void);
    void (APIENTRYP glLoadMatrixf_) (const  GLfloat  * m);
    void (APIENTRYP glLoadMatrixd_) (const  GLdouble  * m);
    void (APIENTRYP glMatrixMode_) (GLenum mode);
    void (APIENTRYP glMultMatrixf_) (const  GLfloat  * m);
    void (APIENTRYP glMultMatrixd_) (const  GLdouble  * m);
    void (APIENTRYP glOrtho_) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    void (APIENTRYP glPopMatrix_) (void);
    void (APIENTRYP glPushMatrix_) (void);
    void (APIENTRYP glRotated_) (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
    void (APIENTRYP glRotatef_) (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glScaled_) (GLdouble x, GLdouble y, GLdouble z);
    void (APIENTRYP glScalef_) (GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glTranslated_) (GLdouble x, GLdouble y, GLdouble z);
    void (APIENTRYP glTranslatef_) (GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glDrawArrays_) (GLenum mode, GLint first, GLsizei count);
    void (APIENTRYP glDrawElements_) (GLenum mode, GLsizei count, GLenum type, const void * indices);
    void (APIENTRYP glGetPointerv_) (GLenum pname, void ** params);
    void (APIENTRYP glPolygonOffset_) (GLfloat factor, GLfloat units);
    void (APIENTRYP glCopyTexImage1D_) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    void (APIENTRYP glCopyTexImage2D_) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    void (APIENTRYP glCopyTexSubImage1D_) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    void (APIENTRYP glCopyTexSubImage2D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    void (APIENTRYP glTexSubImage1D_) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glTexSubImage2D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glBindTexture_) (GLenum target, GLuint texture);
    void (APIENTRYP glDeleteTextures_) (GLsizei n, const  GLuint  * textures);
    void (APIENTRYP glGenTextures_) (GLsizei n, GLuint  * textures);
    GLboolean (APIENTRYP glIsTexture_) (GLuint texture);
    void (APIENTRYP glArrayElement_) (GLint i);
    void (APIENTRYP glColorPointer_) (GLint size, GLenum type, GLsizei stride, const void * pointer);
    void (APIENTRYP glDisableClientState_) (GLenum array);
    void (APIENTRYP glEdgeFlagPointer_) (GLsizei stride, const void * pointer);
    void (APIENTRYP glEnableClientState_) (GLenum array);
    void (APIENTRYP glIndexPointer_) (GLenum type, GLsizei stride, const void * pointer);
    void (APIENTRYP glInterleavedArrays_) (GLenum format, GLsizei stride, const void * pointer);
    void (APIENTRYP glNormalPointer_) (GLenum type, GLsizei stride, const void * pointer);
    void (APIENTRYP glTexCoordPointer_) (GLint size, GLenum type, GLsizei stride, const void * pointer);
    void (APIENTRYP glVertexPointer_) (GLint size, GLenum type, GLsizei stride, const void * pointer);
    GLboolean (APIENTRYP glAreTexturesResident_) (GLsizei n, const  GLuint  * textures, GLboolean  * residences);
    void (APIENTRYP glPrioritizeTextures_) (GLsizei n, const  GLuint  * textures, const  GLfloat  * priorities);
    void (APIENTRYP glIndexub_) (GLubyte c);
    void (APIENTRYP glIndexubv_) (const  GLubyte  * c);
    void (APIENTRYP glPopClientAttrib_) (void);
    void (APIENTRYP glPushClientAttrib_) (GLbitfield mask);
    void (APIENTRYP glDrawRangeElements_) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
    void (APIENTRYP glTexImage3D_) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glTexSubImage3D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glCopyTexSubImage3D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    void (APIENTRYP glActiveTexture_) (GLenum texture);
    void (APIENTRYP glSampleCoverage_) (GLfloat value, GLboolean invert);
    void (APIENTRYP glCompressedTexImage3D_) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
    void (APIENTRYP glCompressedTexImage2D_) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
    void (APIENTRYP glCompressedTexImage1D_) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
    void (APIENTRYP glCompressedTexSubImage3D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
    void (APIENTRYP glCompressedTexSubImage2D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
    void (APIENTRYP glCompressedTexSubImage1D_) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
    void (APIENTRYP glGetCompressedTexImage_) (GLenum target, GLint level, void * img);
    void (APIENTRYP glClientActiveTexture_) (GLenum texture);
    void (APIENTRYP glMultiTexCoord1d_) (GLenum target, GLdouble s);
    void (APIENTRYP glMultiTexCoord1dv_) (GLenum target, const  GLdouble  * v);
    void (APIENTRYP glMultiTexCoord1f_) (GLenum target, GLfloat s);
    void (APIENTRYP glMultiTexCoord1fv_) (GLenum target, const  GLfloat  * v);
    void (APIENTRYP glMultiTexCoord1i_) (GLenum target, GLint s);
    void (APIENTRYP glMultiTexCoord1iv_) (GLenum target, const  GLint  * v);
    void (APIENTRYP glMultiTexCoord1s_) (GLenum target, GLshort s);
    void (APIENTRYP glMultiTexCoord1sv_) (GLenum target, const  GLshort  * v);
    void (APIENTRYP glMultiTexCoord2d_) (GLenum target, GLdouble s, GLdouble t);
    void (APIENTRYP glMultiTexCoord2dv_) (GLenum target, const  GLdouble  * v);
    void (APIENTRYP glMultiTexCoord2f_) (GLenum target, GLfloat s, GLfloat t);
    void (APIENTRYP glMultiTexCoord2fv_) (GLenum target, const  GLfloat  * v);
    void (APIENTRYP glMultiTexCoord2i_) (GLenum target, GLint s, GLint t);
    void (APIENTRYP glMultiTexCoord2iv_) (GLenum target, const  GLint  * v);
    void (APIENTRYP glMultiTexCoord2s_) (GLenum target, GLshort s, GLshort t);
    void (APIENTRYP glMultiTexCoord2sv_) (GLenum target, const  GLshort  * v);
    void (APIENTRYP glMultiTexCoord3d_) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
    void (APIENTRYP glMultiTexCoord3dv_) (GLenum target, const  GLdouble  * v);
    void (APIENTRYP glMultiTexCoord3f_) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
    void (APIENTRYP glMultiTexCoord3fv_) (GLenum target, const  GLfloat  * v);
    void (APIENTRYP glMultiTexCoord3i_) (GLenum target, GLint s, GLint t, GLint r);
    void (APIENTRYP glMultiTexCoord3iv_) (GLenum target, const  GLint  * v);
    void (APIENTRYP glMultiTexCoord3s_) (GLenum target, GLshort s, GLshort t, GLshort r);
    void (APIENTRYP glMultiTexCoord3sv_) (GLenum target, const  GLshort  * v);
    void (APIENTRYP glMultiTexCoord4d_) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
    void (APIENTRYP glMultiTexCoord4dv_) (GLenum target, const  GLdouble  * v);
    void (APIENTRYP glMultiTexCoord4f_) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    void (APIENTRYP glMultiTexCoord4fv_) (GLenum target, const  GLfloat  * v);
    void (APIENTRYP glMultiTexCoord4i_) (GLenum target, GLint s, GLint t, GLint r, GLint q);
    void (APIENTRYP glMultiTexCoord4iv_) (GLenum target, const  GLint  * v);
    void (APIENTRYP glMultiTexCoord4s_) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
    void (APIENTRYP glMultiTexCoord4sv_) (GLenum target, const  GLshort  * v);
    void (APIENTRYP glLoadTransposeMatrixf_) (const  GLfloat  * m);
    void (APIENTRYP glLoadTransposeMatrixd_) (const  GLdouble  * m);
    void (APIENTRYP glMultTransposeMatrixf_) (const  GLfloat  * m);
    void (APIENTRYP glMultTransposeMatrixd_) (const  GLdouble  * m);
    void (APIENTRYP glBlendFuncSeparate_) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    void (APIENTRYP glMultiDrawArrays_) (GLenum mode, const  GLint  * first, const  GLsizei  * count, GLsizei drawcount);
    void (APIENTRYP glMultiDrawElements_) (GLenum mode, const  GLsizei  * count, GLenum type, const void *const* indices, GLsizei drawcount);
    void (APIENTRYP glPointParameterf_) (GLenum pname, GLfloat param);
    void (APIENTRYP glPointParameterfv_) (GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glPointParameteri_) (GLenum pname, GLint param);
    void (APIENTRYP glPointParameteriv_) (GLenum pname, const  GLint  * params);
    void (APIENTRYP glFogCoordf_) (GLfloat coord);
    void (APIENTRYP glFogCoordfv_) (const  GLfloat  * coord);
    void (APIENTRYP glFogCoordd_) (GLdouble coord);
    void (APIENTRYP glFogCoorddv_) (const  GLdouble  * coord);
    void (APIENTRYP glFogCoordPointer_) (GLenum type, GLsizei stride, const void * pointer);
    void (APIENTRYP glSecondaryColor3b_) (GLbyte red, GLbyte green, GLbyte blue);
    void (APIENTRYP glSecondaryColor3bv_) (const  GLbyte  * v);
    void (APIENTRYP glSecondaryColor3d_) (GLdouble red, GLdouble green, GLdouble blue);
    void (APIENTRYP glSecondaryColor3dv_) (const  GLdouble  * v);
    void (APIENTRYP glSecondaryColor3f_) (GLfloat red, GLfloat green, GLfloat blue);
    void (APIENTRYP glSecondaryColor3fv_) (const  GLfloat  * v);
    void (APIENTRYP glSecondaryColor3i_) (GLint red, GLint green, GLint blue);
    void (APIENTRYP glSecondaryColor3iv_) (const  GLint  * v);
    void (APIENTRYP glSecondaryColor3s_) (GLshort red, GLshort green, GLshort blue);
    void (APIENTRYP glSecondaryColor3sv_) (const  GLshort  * v);
    void (APIENTRYP glSecondaryColor3ub_) (GLubyte red, GLubyte green, GLubyte blue);
    void (APIENTRYP glSecondaryColor3ubv_) (const  GLubyte  * v);
    void (APIENTRYP glSecondaryColor3ui_) (GLuint red, GLuint green, GLuint blue);
    void (APIENTRYP glSecondaryColor3uiv_) (const  GLuint  * v);
    void (APIENTRYP glSecondaryColor3us_) (GLushort red, GLushort green, GLushort blue);
    void (APIENTRYP glSecondaryColor3usv_) (const  GLushort  * v);
    void (APIENTRYP glSecondaryColorPointer_) (GLint size, GLenum type, GLsizei stride, const void * pointer);
    void (APIENTRYP glWindowPos2d_) (GLdouble x, GLdouble y);
    void (APIENTRYP glWindowPos2dv_) (const  GLdouble  * v);
    void (APIENTRYP glWindowPos2f_) (GLfloat x, GLfloat y);
    void (APIENTRYP glWindowPos2fv_) (const  GLfloat  * v);
    void (APIENTRYP glWindowPos2i_) (GLint x, GLint y);
    void (APIENTRYP glWindowPos2iv_) (const  GLint  * v);
    void (APIENTRYP glWindowPos2s_) (GLshort x, GLshort y);
    void (APIENTRYP glWindowPos2sv_) (const  GLshort  * v);
    void (APIENTRYP glWindowPos3d_) (GLdouble x, GLdouble y, GLdouble z);
    void (APIENTRYP glWindowPos3dv_) (const  GLdouble  * v);
    void (APIENTRYP glWindowPos3f_) (GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glWindowPos3fv_) (const  GLfloat  * v);
    void (APIENTRYP glWindowPos3i_) (GLint x, GLint y, GLint z);
    void (APIENTRYP glWindowPos3iv_) (const  GLint  * v);
    void (APIENTRYP glWindowPos3s_) (GLshort x, GLshort y, GLshort z);
    void (APIENTRYP glWindowPos3sv_) (const  GLshort  * v);
    void (APIENTRYP glBlendColor_) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void (APIENTRYP glBlendEquation_) (GLenum mode);
    void (APIENTRYP glGenQueries_) (GLsizei n, GLuint  * ids);
    void (APIENTRYP glDeleteQueries_) (GLsizei n, const  GLuint  * ids);
    GLboolean (APIENTRYP glIsQuery_) (GLuint id);
    void (APIENTRYP glBeginQuery_) (GLenum target, GLuint id);
    void (APIENTRYP glEndQuery_) (GLenum target);
    void (APIENTRYP glGetQueryiv_) (GLenum target, GLenum pname, GLint  * params);
    void (APIENTRYP glGetQueryObjectiv_) (GLuint id, GLenum pname, GLint  * params);
    void (APIENTRYP glGetQueryObjectuiv_) (GLuint id, GLenum pname, GLuint  * params);
    void (APIENTRYP glBindBuffer_) (GLenum target, GLuint buffer);
    void (APIENTRYP glDeleteBuffers_) (GLsizei n, const  GLuint  * buffers);
    void (APIENTRYP glGenBuffers_) (GLsizei n, GLuint  * buffers);
    GLboolean (APIENTRYP glIsBuffer_) (GLuint buffer);
    void (APIENTRYP glBufferData_) (GLenum target, GLsizeiptr size, const void * data, GLenum usage);
    void (APIENTRYP glBufferSubData_) (GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
    void (APIENTRYP glGetBufferSubData_) (GLenum target, GLintptr offset, GLsizeiptr size, void * data);
    void * (APIENTRYP glMapBuffer_) (GLenum target, GLenum access);
    GLboolean (APIENTRYP glUnmapBuffer_) (GLenum target);
    void (APIENTRYP glGetBufferParameteriv_) (GLenum target, GLenum pname, GLint  * params);
    void (APIENTRYP glGetBufferPointerv_) (GLenum target, GLenum pname, void ** params);
    void (APIENTRYP glBlendEquationSeparate_) (GLenum modeRGB, GLenum modeAlpha);
    void (APIENTRYP glDrawBuffers_) (GLsizei n, const  GLenum  * bufs);
    void (APIENTRYP glStencilOpSeparate_) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    void (APIENTRYP glStencilFuncSeparate_) (GLenum face, GLenum func, GLint ref, GLuint mask);
    void (APIENTRYP glStencilMaskSeparate_) (GLenum face, GLuint mask);
    void (APIENTRYP glAttachShader_) (GLuint program, GLuint shader);
    void (APIENTRYP glBindAttribLocation_) (GLuint program, GLuint index, const  GLchar  * name);
    void (APIENTRYP glCompileShader_) (GLuint shader);
    GLuint (APIENTRYP glCreateProgram_) (void);
    GLuint (APIENTRYP glCreateShader_) (GLenum type);
    void (APIENTRYP glDeleteProgram_) (GLuint program);
    void (APIENTRYP glDeleteShader_) (GLuint shader);
    void (APIENTRYP glDetachShader_) (GLuint program, GLuint shader);
    void (APIENTRYP glDisableVertexAttribArray_) (GLuint index);
    void (APIENTRYP glEnableVertexAttribArray_) (GLuint index);
    void (APIENTRYP glGetActiveAttrib_) (GLuint program, GLuint index, GLsizei bufSize, GLsizei  * length, GLint  * size, GLenum  * type, GLchar  * name);
    void (APIENTRYP glGetActiveUniform_) (GLuint program, GLuint index, GLsizei bufSize, GLsizei  * length, GLint  * size, GLenum  * type, GLchar  * name);
    void (APIENTRYP glGetAttachedShaders_) (GLuint program, GLsizei maxCount, GLsizei  * count, GLuint  * shaders);
    GLint (APIENTRYP glGetAttribLocation_) (GLuint program, const  GLchar  * name);
    void (APIENTRYP glGetProgramiv_) (GLuint program, GLenum pname, GLint  * params);
    void (APIENTRYP glGetProgramInfoLog_) (GLuint program, GLsizei bufSize, GLsizei  * length, GLchar  * infoLog);
    void (APIENTRYP glGetShaderiv_) (GLuint shader, GLenum pname, GLint  * params);
    void (APIENTRYP glGetShaderInfoLog_) (GLuint shader, GLsizei bufSize, GLsizei  * length, GLchar  * infoLog);
    void (APIENTRYP glGetShaderSource_) (GLuint shader, GLsizei bufSize, GLsizei  * length, GLchar  * source);
    GLint (APIENTRYP glGetUniformLocation_) (GLuint program, const  GLchar  * name);
    void (APIENTRYP glGetUniformfv_) (GLuint program, GLint location, GLfloat  * params);
    void (APIENTRYP glGetUniformiv_) (GLuint program, GLint location, GLint  * params);
    void (APIENTRYP glGetVertexAttribdv_) (GLuint index, GLenum pname, GLdouble  * params);
    void (APIENTRYP glGetVertexAttribfv_) (GLuint index, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetVertexAttribiv_) (GLuint index, GLenum pname, GLint  * params);
    void (APIENTRYP glGetVertexAttribPointerv_) (GLuint index, GLenum pname, void ** pointer);
    GLboolean (APIENTRYP glIsProgram_) (GLuint program);
    GLboolean (APIENTRYP glIsShader_) (GLuint shader);
    void (APIENTRYP glLinkProgram_) (GLuint program);
    void (APIENTRYP glShaderSource_) (GLuint shader, GLsizei count, const  GLchar  *const* string, const  GLint  * length);
    void (APIENTRYP glUseProgram_) (GLuint program);
    void (APIENTRYP glUniform1f_) (GLint location, GLfloat v0);
    void (APIENTRYP glUniform2f_) (GLint location, GLfloat v0, GLfloat v1);
    void (APIENTRYP glUniform3f_) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    void (APIENTRYP glUniform4f_) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    void (APIENTRYP glUniform1i_) (GLint location, GLint v0);
    void (APIENTRYP glUniform2i_) (GLint location, GLint v0, GLint v1);
    void (APIENTRYP glUniform3i_) (GLint location, GLint v0, GLint v1, GLint v2);
    void (APIENTRYP glUniform4i_) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    void (APIENTRYP glUniform1fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform2fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform3fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform4fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform1iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniform2iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniform3iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniform4iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniformMatrix2fv_) (GLint location, GLsizei count, GLboolean transpose, const  GLfloat  * value);
    void (APIENTRYP glUniformMatrix3fv_) (GLint location, GLsizei count, GLboolean transpose, const  GLfloat  * value);
    void (APIENTRYP glUniformMatrix4fv_) (GLint location, GLsizei count, GLboolean transpose, const  GLfloat  * value);
    void (APIENTRYP glValidateProgram_) (GLuint program);
    void (APIENTRYP glVertexAttrib1d_) (GLuint index, GLdouble x);
    void (APIENTRYP glVertexAttrib1dv_) (GLuint index, const  GLdouble  * v);
    void (APIENTRYP glVertexAttrib1f_) (GLuint index, GLfloat x);
    void (APIENTRYP glVertexAttrib1fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttrib1s_) (GLuint index, GLshort x);
    void (APIENTRYP glVertexAttrib1sv_) (GLuint index, const  GLshort  * v);
    void (APIENTRYP glVertexAttrib2d_) (GLuint index, GLdouble x, GLdouble y);
    void (APIENTRYP glVertexAttrib2dv_) (GLuint index, const  GLdouble  * v);
    void (APIENTRYP glVertexAttrib2f_) (GLuint index, GLfloat x, GLfloat y);
    void (APIENTRYP glVertexAttrib2fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttrib2s_) (GLuint index, GLshort x, GLshort y);
    void (APIENTRYP glVertexAttrib2sv_) (GLuint index, const  GLshort  * v);
    void (APIENTRYP glVertexAttrib3d_) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    void (APIENTRYP glVertexAttrib3dv_) (GLuint index, const  GLdouble  * v);
    void (APIENTRYP glVertexAttrib3f_) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glVertexAttrib3fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttrib3s_) (GLuint index, GLshort x, GLshort y, GLshort z);
    void (APIENTRYP glVertexAttrib3sv_) (GLuint index, const  GLshort  * v);
    void (APIENTRYP glVertexAttrib4Nbv_) (GLuint index, const  GLbyte  * v);
    void (APIENTRYP glVertexAttrib4Niv_) (GLuint index, const  GLint  * v);
    void (APIENTRYP glVertexAttrib4Nsv_) (GLuint index, const  GLshort  * v);
    void (APIENTRYP glVertexAttrib4Nub_) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    void (APIENTRYP glVertexAttrib4Nubv_) (GLuint index, const  GLubyte  * v);
    void (APIENTRYP glVertexAttrib4Nuiv_) (GLuint index, const  GLuint  * v);
    void (APIENTRYP glVertexAttrib4Nusv_) (GLuint index, const  GLushort  * v);
    void (APIENTRYP glVertexAttrib4bv_) (GLuint index, const  GLbyte  * v);
    void (APIENTRYP glVertexAttrib4d_) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    void (APIENTRYP glVertexAttrib4dv_) (GLuint index, const  GLdouble  * v);
    void (APIENTRYP glVertexAttrib4f_) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void (APIENTRYP glVertexAttrib4fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttrib4iv_) (GLuint index, const  GLint  * v);
    void (APIENTRYP glVertexAttrib4s_) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    void (APIENTRYP glVertexAttrib4sv_) (GLuint index, const  GLshort  * v);
    void (APIENTRYP glVertexAttrib4ubv_) (GLuint index, const  GLubyte  * v);
    void (APIENTRYP glVertexAttrib4uiv_) (GLuint index, const  GLuint  * v);
    void (APIENTRYP glVertexAttrib4usv_) (GLuint index, const  GLushort  * v);
    void (APIENTRYP glVertexAttribPointer_) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
  } fps;
} LoadGLapis;

LOADGL_API LoadGLapis oglApis;

/* macros to call OpenGL functions */
#define glCullFace              oglApis.fps.glCullFace_
#define glFrontFace             oglApis.fps.glFrontFace_
#define glHint                  oglApis.fps.glHint_
#define glLineWidth             oglApis.fps.glLineWidth_
#define glPointSize             oglApis.fps.glPointSize_
#define glPolygonMode           oglApis.fps.glPolygonMode_
#define glScissor               oglApis.fps.glScissor_
#define glTexParameterf         oglApis.fps.glTexParameterf_
#define glTexParameterfv        oglApis.fps.glTexParameterfv_
#define glTexParameteri         oglApis.fps.glTexParameteri_
#define glTexParameteriv        oglApis.fps.glTexParameteriv_
#define glTexImage1D            oglApis.fps.glTexImage1D_
#define glTexImage2D            oglApis.fps.glTexImage2D_
#define glDrawBuffer            oglApis.fps.glDrawBuffer_
#define glClear                 oglApis.fps.glClear_
#define glClearColor            oglApis.fps.glClearColor_
#define glClearStencil          oglApis.fps.glClearStencil_
#define glClearDepth            oglApis.fps.glClearDepth_
#define glStencilMask           oglApis.fps.glStencilMask_
#define glColorMask             oglApis.fps.glColorMask_
#define glDepthMask             oglApis.fps.glDepthMask_
#define glDisable               oglApis.fps.glDisable_
#define glEnable                oglApis.fps.glEnable_
#define glFinish                oglApis.fps.glFinish_
#define glFlush                 oglApis.fps.glFlush_
#define glBlendFunc             oglApis.fps.glBlendFunc_
#define glLogicOp               oglApis.fps.glLogicOp_
#define glStencilFunc           oglApis.fps.glStencilFunc_
#define glStencilOp             oglApis.fps.glStencilOp_
#define glDepthFunc             oglApis.fps.glDepthFunc_
#define glPixelStoref           oglApis.fps.glPixelStoref_
#define glPixelStorei           oglApis.fps.glPixelStorei_
#define glReadBuffer            oglApis.fps.glReadBuffer_
#define glReadPixels            oglApis.fps.glReadPixels_
#define glGetBooleanv           oglApis.fps.glGetBooleanv_
#define glGetDoublev            oglApis.fps.glGetDoublev_
#define glGetError              oglApis.fps.glGetError_
#define glGetFloatv             oglApis.fps.glGetFloatv_
#define glGetIntegerv           oglApis.fps.glGetIntegerv_
#define glGetString             oglApis.fps.glGetString_
#define glGetTexImage           oglApis.fps.glGetTexImage_
#define glGetTexParameterfv     oglApis.fps.glGetTexParameterfv_
#define glGetTexParameteriv     oglApis.fps.glGetTexParameteriv_
#define glGetTexLevelParameterfv oglApis.fps.glGetTexLevelParameterfv_
#define glGetTexLevelParameteriv oglApis.fps.glGetTexLevelParameteriv_
#define glIsEnabled             oglApis.fps.glIsEnabled_
#define glDepthRange            oglApis.fps.glDepthRange_
#define glViewport              oglApis.fps.glViewport_
#define glNewList               oglApis.fps.glNewList_
#define glEndList               oglApis.fps.glEndList_
#define glCallList              oglApis.fps.glCallList_
#define glCallLists             oglApis.fps.glCallLists_
#define glDeleteLists           oglApis.fps.glDeleteLists_
#define glGenLists              oglApis.fps.glGenLists_
#define glListBase              oglApis.fps.glListBase_
#define glBegin                 oglApis.fps.glBegin_
#define glBitmap                oglApis.fps.glBitmap_
#define glColor3b               oglApis.fps.glColor3b_
#define glColor3bv              oglApis.fps.glColor3bv_
#define glColor3d               oglApis.fps.glColor3d_
#define glColor3dv              oglApis.fps.glColor3dv_
#define glColor3f               oglApis.fps.glColor3f_
#define glColor3fv              oglApis.fps.glColor3fv_
#define glColor3i               oglApis.fps.glColor3i_
#define glColor3iv              oglApis.fps.glColor3iv_
#define glColor3s               oglApis.fps.glColor3s_
#define glColor3sv              oglApis.fps.glColor3sv_
#define glColor3ub              oglApis.fps.glColor3ub_
#define glColor3ubv             oglApis.fps.glColor3ubv_
#define glColor3ui              oglApis.fps.glColor3ui_
#define glColor3uiv             oglApis.fps.glColor3uiv_
#define glColor3us              oglApis.fps.glColor3us_
#define glColor3usv             oglApis.fps.glColor3usv_
#define glColor4b               oglApis.fps.glColor4b_
#define glColor4bv              oglApis.fps.glColor4bv_
#define glColor4d               oglApis.fps.glColor4d_
#define glColor4dv              oglApis.fps.glColor4dv_
#define glColor4f               oglApis.fps.glColor4f_
#define glColor4fv              oglApis.fps.glColor4fv_
#define glColor4i               oglApis.fps.glColor4i_
#define glColor4iv              oglApis.fps.glColor4iv_
#define glColor4s               oglApis.fps.glColor4s_
#define glColor4sv              oglApis.fps.glColor4sv_
#define glColor4ub              oglApis.fps.glColor4ub_
#define glColor4ubv             oglApis.fps.glColor4ubv_
#define glColor4ui              oglApis.fps.glColor4ui_
#define glColor4uiv             oglApis.fps.glColor4uiv_
#define glColor4us              oglApis.fps.glColor4us_
#define glColor4usv             oglApis.fps.glColor4usv_
#define glEdgeFlag              oglApis.fps.glEdgeFlag_
#define glEdgeFlagv             oglApis.fps.glEdgeFlagv_
#define glEnd                   oglApis.fps.glEnd_
#define glIndexd                oglApis.fps.glIndexd_
#define glIndexdv               oglApis.fps.glIndexdv_
#define glIndexf                oglApis.fps.glIndexf_
#define glIndexfv               oglApis.fps.glIndexfv_
#define glIndexi                oglApis.fps.glIndexi_
#define glIndexiv               oglApis.fps.glIndexiv_
#define glIndexs                oglApis.fps.glIndexs_
#define glIndexsv               oglApis.fps.glIndexsv_
#define glNormal3b              oglApis.fps.glNormal3b_
#define glNormal3bv             oglApis.fps.glNormal3bv_
#define glNormal3d              oglApis.fps.glNormal3d_
#define glNormal3dv             oglApis.fps.glNormal3dv_
#define glNormal3f              oglApis.fps.glNormal3f_
#define glNormal3fv             oglApis.fps.glNormal3fv_
#define glNormal3i              oglApis.fps.glNormal3i_
#define glNormal3iv             oglApis.fps.glNormal3iv_
#define glNormal3s              oglApis.fps.glNormal3s_
#define glNormal3sv             oglApis.fps.glNormal3sv_
#define glRasterPos2d           oglApis.fps.glRasterPos2d_
#define glRasterPos2dv          oglApis.fps.glRasterPos2dv_
#define glRasterPos2f           oglApis.fps.glRasterPos2f_
#define glRasterPos2fv          oglApis.fps.glRasterPos2fv_
#define glRasterPos2i           oglApis.fps.glRasterPos2i_
#define glRasterPos2iv          oglApis.fps.glRasterPos2iv_
#define glRasterPos2s           oglApis.fps.glRasterPos2s_
#define glRasterPos2sv          oglApis.fps.glRasterPos2sv_
#define glRasterPos3d           oglApis.fps.glRasterPos3d_
#define glRasterPos3dv          oglApis.fps.glRasterPos3dv_
#define glRasterPos3f           oglApis.fps.glRasterPos3f_
#define glRasterPos3fv          oglApis.fps.glRasterPos3fv_
#define glRasterPos3i           oglApis.fps.glRasterPos3i_
#define glRasterPos3iv          oglApis.fps.glRasterPos3iv_
#define glRasterPos3s           oglApis.fps.glRasterPos3s_
#define glRasterPos3sv          oglApis.fps.glRasterPos3sv_
#define glRasterPos4d           oglApis.fps.glRasterPos4d_
#define glRasterPos4dv          oglApis.fps.glRasterPos4dv_
#define glRasterPos4f           oglApis.fps.glRasterPos4f_
#define glRasterPos4fv          oglApis.fps.glRasterPos4fv_
#define glRasterPos4i           oglApis.fps.glRasterPos4i_
#define glRasterPos4iv          oglApis.fps.glRasterPos4iv_
#define glRasterPos4s           oglApis.fps.glRasterPos4s_
#define glRasterPos4sv          oglApis.fps.glRasterPos4sv_
#define glRectd                 oglApis.fps.glRectd_
#define glRectdv                oglApis.fps.glRectdv_
#define glRectf                 oglApis.fps.glRectf_
#define glRectfv                oglApis.fps.glRectfv_
#define glRecti                 oglApis.fps.glRecti_
#define glRectiv                oglApis.fps.glRectiv_
#define glRects                 oglApis.fps.glRects_
#define glRectsv                oglApis.fps.glRectsv_
#define glTexCoord1d            oglApis.fps.glTexCoord1d_
#define glTexCoord1dv           oglApis.fps.glTexCoord1dv_
#define glTexCoord1f            oglApis.fps.glTexCoord1f_
#define glTexCoord1fv           oglApis.fps.glTexCoord1fv_
#define glTexCoord1i            oglApis.fps.glTexCoord1i_
#define glTexCoord1iv           oglApis.fps.glTexCoord1iv_
#define glTexCoord1s            oglApis.fps.glTexCoord1s_
#define glTexCoord1sv           oglApis.fps.glTexCoord1sv_
#define glTexCoord2d            oglApis.fps.glTexCoord2d_
#define glTexCoord2dv           oglApis.fps.glTexCoord2dv_
#define glTexCoord2f            oglApis.fps.glTexCoord2f_
#define glTexCoord2fv           oglApis.fps.glTexCoord2fv_
#define glTexCoord2i            oglApis.fps.glTexCoord2i_
#define glTexCoord2iv           oglApis.fps.glTexCoord2iv_
#define glTexCoord2s            oglApis.fps.glTexCoord2s_
#define glTexCoord2sv           oglApis.fps.glTexCoord2sv_
#define glTexCoord3d            oglApis.fps.glTexCoord3d_
#define glTexCoord3dv           oglApis.fps.glTexCoord3dv_
#define glTexCoord3f            oglApis.fps.glTexCoord3f_
#define glTexCoord3fv           oglApis.fps.glTexCoord3fv_
#define glTexCoord3i            oglApis.fps.glTexCoord3i_
#define glTexCoord3iv           oglApis.fps.glTexCoord3iv_
#define glTexCoord3s            oglApis.fps.glTexCoord3s_
#define glTexCoord3sv           oglApis.fps.glTexCoord3sv_
#define glTexCoord4d            oglApis.fps.glTexCoord4d_
#define glTexCoord4dv           oglApis.fps.glTexCoord4dv_
#define glTexCoord4f            oglApis.fps.glTexCoord4f_
#define glTexCoord4fv           oglApis.fps.glTexCoord4fv_
#define glTexCoord4i            oglApis.fps.glTexCoord4i_
#define glTexCoord4iv           oglApis.fps.glTexCoord4iv_
#define glTexCoord4s            oglApis.fps.glTexCoord4s_
#define glTexCoord4sv           oglApis.fps.glTexCoord4sv_
#define glVertex2d              oglApis.fps.glVertex2d_
#define glVertex2dv             oglApis.fps.glVertex2dv_
#define glVertex2f              oglApis.fps.glVertex2f_
#define glVertex2fv             oglApis.fps.glVertex2fv_
#define glVertex2i              oglApis.fps.glVertex2i_
#define glVertex2iv             oglApis.fps.glVertex2iv_
#define glVertex2s              oglApis.fps.glVertex2s_
#define glVertex2sv             oglApis.fps.glVertex2sv_
#define glVertex3d              oglApis.fps.glVertex3d_
#define glVertex3dv             oglApis.fps.glVertex3dv_
#define glVertex3f              oglApis.fps.glVertex3f_
#define glVertex3fv             oglApis.fps.glVertex3fv_
#define glVertex3i              oglApis.fps.glVertex3i_
#define glVertex3iv             oglApis.fps.glVertex3iv_
#define glVertex3s              oglApis.fps.glVertex3s_
#define glVertex3sv             oglApis.fps.glVertex3sv_
#define glVertex4d              oglApis.fps.glVertex4d_
#define glVertex4dv             oglApis.fps.glVertex4dv_
#define glVertex4f              oglApis.fps.glVertex4f_
#define glVertex4fv             oglApis.fps.glVertex4fv_
#define glVertex4i              oglApis.fps.glVertex4i_
#define glVertex4iv             oglApis.fps.glVertex4iv_
#define glVertex4s              oglApis.fps.glVertex4s_
#define glVertex4sv             oglApis.fps.glVertex4sv_
#define glClipPlane             oglApis.fps.glClipPlane_
#define glColorMaterial         oglApis.fps.glColorMaterial_
#define glFogf                  oglApis.fps.glFogf_
#define glFogfv                 oglApis.fps.glFogfv_
#define glFogi                  oglApis.fps.glFogi_
#define glFogiv                 oglApis.fps.glFogiv_
#define glLightf                oglApis.fps.glLightf_
#define glLightfv               oglApis.fps.glLightfv_
#define glLighti                oglApis.fps.glLighti_
#define glLightiv               oglApis.fps.glLightiv_
#define glLightModelf           oglApis.fps.glLightModelf_
#define glLightModelfv          oglApis.fps.glLightModelfv_
#define glLightModeli           oglApis.fps.glLightModeli_
#define glLightModeliv          oglApis.fps.glLightModeliv_
#define glLineStipple           oglApis.fps.glLineStipple_
#define glMaterialf             oglApis.fps.glMaterialf_
#define glMaterialfv            oglApis.fps.glMaterialfv_
#define glMateriali             oglApis.fps.glMateriali_
#define glMaterialiv            oglApis.fps.glMaterialiv_
#define glPolygonStipple        oglApis.fps.glPolygonStipple_
#define glShadeModel            oglApis.fps.glShadeModel_
#define glTexEnvf               oglApis.fps.glTexEnvf_
#define glTexEnvfv              oglApis.fps.glTexEnvfv_
#define glTexEnvi               oglApis.fps.glTexEnvi_
#define glTexEnviv              oglApis.fps.glTexEnviv_
#define glTexGend               oglApis.fps.glTexGend_
#define glTexGendv              oglApis.fps.glTexGendv_
#define glTexGenf               oglApis.fps.glTexGenf_
#define glTexGenfv              oglApis.fps.glTexGenfv_
#define glTexGeni               oglApis.fps.glTexGeni_
#define glTexGeniv              oglApis.fps.glTexGeniv_
#define glFeedbackBuffer        oglApis.fps.glFeedbackBuffer_
#define glSelectBuffer          oglApis.fps.glSelectBuffer_
#define glRenderMode            oglApis.fps.glRenderMode_
#define glInitNames             oglApis.fps.glInitNames_
#define glLoadName              oglApis.fps.glLoadName_
#define glPassThrough           oglApis.fps.glPassThrough_
#define glPopName               oglApis.fps.glPopName_
#define glPushName              oglApis.fps.glPushName_
#define glClearAccum            oglApis.fps.glClearAccum_
#define glClearIndex            oglApis.fps.glClearIndex_
#define glIndexMask             oglApis.fps.glIndexMask_
#define glAccum                 oglApis.fps.glAccum_
#define glPopAttrib             oglApis.fps.glPopAttrib_
#define glPushAttrib            oglApis.fps.glPushAttrib_
#define glMap1d                 oglApis.fps.glMap1d_
#define glMap1f                 oglApis.fps.glMap1f_
#define glMap2d                 oglApis.fps.glMap2d_
#define glMap2f                 oglApis.fps.glMap2f_
#define glMapGrid1d             oglApis.fps.glMapGrid1d_
#define glMapGrid1f             oglApis.fps.glMapGrid1f_
#define glMapGrid2d             oglApis.fps.glMapGrid2d_
#define glMapGrid2f             oglApis.fps.glMapGrid2f_
#define glEvalCoord1d           oglApis.fps.glEvalCoord1d_
#define glEvalCoord1dv          oglApis.fps.glEvalCoord1dv_
#define glEvalCoord1f           oglApis.fps.glEvalCoord1f_
#define glEvalCoord1fv          oglApis.fps.glEvalCoord1fv_
#define glEvalCoord2d           oglApis.fps.glEvalCoord2d_
#define glEvalCoord2dv          oglApis.fps.glEvalCoord2dv_
#define glEvalCoord2f           oglApis.fps.glEvalCoord2f_
#define glEvalCoord2fv          oglApis.fps.glEvalCoord2fv_
#define glEvalMesh1             oglApis.fps.glEvalMesh1_
#define glEvalPoint1            oglApis.fps.glEvalPoint1_
#define glEvalMesh2             oglApis.fps.glEvalMesh2_
#define glEvalPoint2            oglApis.fps.glEvalPoint2_
#define glAlphaFunc             oglApis.fps.glAlphaFunc_
#define glPixelZoom             oglApis.fps.glPixelZoom_
#define glPixelTransferf        oglApis.fps.glPixelTransferf_
#define glPixelTransferi        oglApis.fps.glPixelTransferi_
#define glPixelMapfv            oglApis.fps.glPixelMapfv_
#define glPixelMapuiv           oglApis.fps.glPixelMapuiv_
#define glPixelMapusv           oglApis.fps.glPixelMapusv_
#define glCopyPixels            oglApis.fps.glCopyPixels_
#define glDrawPixels            oglApis.fps.glDrawPixels_
#define glGetClipPlane          oglApis.fps.glGetClipPlane_
#define glGetLightfv            oglApis.fps.glGetLightfv_
#define glGetLightiv            oglApis.fps.glGetLightiv_
#define glGetMapdv              oglApis.fps.glGetMapdv_
#define glGetMapfv              oglApis.fps.glGetMapfv_
#define glGetMapiv              oglApis.fps.glGetMapiv_
#define glGetMaterialfv         oglApis.fps.glGetMaterialfv_
#define glGetMaterialiv         oglApis.fps.glGetMaterialiv_
#define glGetPixelMapfv         oglApis.fps.glGetPixelMapfv_
#define glGetPixelMapuiv        oglApis.fps.glGetPixelMapuiv_
#define glGetPixelMapusv        oglApis.fps.glGetPixelMapusv_
#define glGetPolygonStipple     oglApis.fps.glGetPolygonStipple_
#define glGetTexEnvfv           oglApis.fps.glGetTexEnvfv_
#define glGetTexEnviv           oglApis.fps.glGetTexEnviv_
#define glGetTexGendv           oglApis.fps.glGetTexGendv_
#define glGetTexGenfv           oglApis.fps.glGetTexGenfv_
#define glGetTexGeniv           oglApis.fps.glGetTexGeniv_
#define glIsList                oglApis.fps.glIsList_
#define glFrustum               oglApis.fps.glFrustum_
#define glLoadIdentity          oglApis.fps.glLoadIdentity_
#define glLoadMatrixf           oglApis.fps.glLoadMatrixf_
#define glLoadMatrixd           oglApis.fps.glLoadMatrixd_
#define glMatrixMode            oglApis.fps.glMatrixMode_
#define glMultMatrixf           oglApis.fps.glMultMatrixf_
#define glMultMatrixd           oglApis.fps.glMultMatrixd_
#define glOrtho                 oglApis.fps.glOrtho_
#define glPopMatrix             oglApis.fps.glPopMatrix_
#define glPushMatrix            oglApis.fps.glPushMatrix_
#define glRotated               oglApis.fps.glRotated_
#define glRotatef               oglApis.fps.glRotatef_
#define glScaled                oglApis.fps.glScaled_
#define glScalef                oglApis.fps.glScalef_
#define glTranslated            oglApis.fps.glTranslated_
#define glTranslatef            oglApis.fps.glTranslatef_
#define glDrawArrays            oglApis.fps.glDrawArrays_
#define glDrawElements          oglApis.fps.glDrawElements_
#define glGetPointerv           oglApis.fps.glGetPointerv_
#define glPolygonOffset         oglApis.fps.glPolygonOffset_
#define glCopyTexImage1D        oglApis.fps.glCopyTexImage1D_
#define glCopyTexImage2D        oglApis.fps.glCopyTexImage2D_
#define glCopyTexSubImage1D     oglApis.fps.glCopyTexSubImage1D_
#define glCopyTexSubImage2D     oglApis.fps.glCopyTexSubImage2D_
#define glTexSubImage1D         oglApis.fps.glTexSubImage1D_
#define glTexSubImage2D         oglApis.fps.glTexSubImage2D_
#define glBindTexture           oglApis.fps.glBindTexture_
#define glDeleteTextures        oglApis.fps.glDeleteTextures_
#define glGenTextures           oglApis.fps.glGenTextures_
#define glIsTexture             oglApis.fps.glIsTexture_
#define glArrayElement          oglApis.fps.glArrayElement_
#define glColorPointer          oglApis.fps.glColorPointer_
#define glDisableClientState    oglApis.fps.glDisableClientState_
#define glEdgeFlagPointer       oglApis.fps.glEdgeFlagPointer_
#define glEnableClientState     oglApis.fps.glEnableClientState_
#define glIndexPointer          oglApis.fps.glIndexPointer_
#define glInterleavedArrays     oglApis.fps.glInterleavedArrays_
#define glNormalPointer         oglApis.fps.glNormalPointer_
#define glTexCoordPointer       oglApis.fps.glTexCoordPointer_
#define glVertexPointer         oglApis.fps.glVertexPointer_
#define glAreTexturesResident   oglApis.fps.glAreTexturesResident_
#define glPrioritizeTextures    oglApis.fps.glPrioritizeTextures_
#define glIndexub               oglApis.fps.glIndexub_
#define glIndexubv              oglApis.fps.glIndexubv_
#define glPopClientAttrib       oglApis.fps.glPopClientAttrib_
#define glPushClientAttrib      oglApis.fps.glPushClientAttrib_
#define glDrawRangeElements     oglApis.fps.glDrawRangeElements_
#define glTexImage3D            oglApis.fps.glTexImage3D_
#define glTexSubImage3D         oglApis.fps.glTexSubImage3D_
#define glCopyTexSubImage3D     oglApis.fps.glCopyTexSubImage3D_
#define glActiveTexture         oglApis.fps.glActiveTexture_
#define glSampleCoverage        oglApis.fps.glSampleCoverage_
#define glCompressedTexImage3D  oglApis.fps.glCompressedTexImage3D_
#define glCompressedTexImage2D  oglApis.fps.glCompressedTexImage2D_
#define glCompressedTexImage1D  oglApis.fps.glCompressedTexImage1D_
#define glCompressedTexSubImage3D oglApis.fps.glCompressedTexSubImage3D_
#define glCompressedTexSubImage2D oglApis.fps.glCompressedTexSubImage2D_
#define glCompressedTexSubImage1D oglApis.fps.glCompressedTexSubImage1D_
#define glGetCompressedTexImage oglApis.fps.glGetCompressedTexImage_
#define glClientActiveTexture   oglApis.fps.glClientActiveTexture_
#define glMultiTexCoord1d       oglApis.fps.glMultiTexCoord1d_
#define glMultiTexCoord1dv      oglApis.fps.glMultiTexCoord1dv_
#define glMultiTexCoord1f       oglApis.fps.glMultiTexCoord1f_
#define glMultiTexCoord1fv      oglApis.fps.glMultiTexCoord1fv_
#define glMultiTexCoord1i       oglApis.fps.glMultiTexCoord1i_
#define glMultiTexCoord1iv      oglApis.fps.glMultiTexCoord1iv_
#define glMultiTexCoord1s       oglApis.fps.glMultiTexCoord1s_
#define glMultiTexCoord1sv      oglApis.fps.glMultiTexCoord1sv_
#define glMultiTexCoord2d       oglApis.fps.glMultiTexCoord2d_
#define glMultiTexCoord2dv      oglApis.fps.glMultiTexCoord2dv_
#define glMultiTexCoord2f       oglApis.fps.glMultiTexCoord2f_
#define glMultiTexCoord2fv      oglApis.fps.glMultiTexCoord2fv_
#define glMultiTexCoord2i       oglApis.fps.glMultiTexCoord2i_
#define glMultiTexCoord2iv      oglApis.fps.glMultiTexCoord2iv_
#define glMultiTexCoord2s       oglApis.fps.glMultiTexCoord2s_
#define glMultiTexCoord2sv      oglApis.fps.glMultiTexCoord2sv_
#define glMultiTexCoord3d       oglApis.fps.glMultiTexCoord3d_
#define glMultiTexCoord3dv      oglApis.fps.glMultiTexCoord3dv_
#define glMultiTexCoord3f       oglApis.fps.glMultiTexCoord3f_
#define glMultiTexCoord3fv      oglApis.fps.glMultiTexCoord3fv_
#define glMultiTexCoord3i       oglApis.fps.glMultiTexCoord3i_
#define glMultiTexCoord3iv      oglApis.fps.glMultiTexCoord3iv_
#define glMultiTexCoord3s       oglApis.fps.glMultiTexCoord3s_
#define glMultiTexCoord3sv      oglApis.fps.glMultiTexCoord3sv_
#define glMultiTexCoord4d       oglApis.fps.glMultiTexCoord4d_
#define glMultiTexCoord4dv      oglApis.fps.glMultiTexCoord4dv_
#define glMultiTexCoord4f       oglApis.fps.glMultiTexCoord4f_
#define glMultiTexCoord4fv      oglApis.fps.glMultiTexCoord4fv_
#define glMultiTexCoord4i       oglApis.fps.glMultiTexCoord4i_
#define glMultiTexCoord4iv      oglApis.fps.glMultiTexCoord4iv_
#define glMultiTexCoord4s       oglApis.fps.glMultiTexCoord4s_
#define glMultiTexCoord4sv      oglApis.fps.glMultiTexCoord4sv_
#define glLoadTransposeMatrixf  oglApis.fps.glLoadTransposeMatrixf_
#define glLoadTransposeMatrixd  oglApis.fps.glLoadTransposeMatrixd_
#define glMultTransposeMatrixf  oglApis.fps.glMultTransposeMatrixf_
#define glMultTransposeMatrixd  oglApis.fps.glMultTransposeMatrixd_
#define glBlendFuncSeparate     oglApis.fps.glBlendFuncSeparate_
#define glMultiDrawArrays       oglApis.fps.glMultiDrawArrays_
#define glMultiDrawElements     oglApis.fps.glMultiDrawElements_
#define glPointParameterf       oglApis.fps.glPointParameterf_
#define glPointParameterfv      oglApis.fps.glPointParameterfv_
#define glPointParameteri       oglApis.fps.glPointParameteri_
#define glPointParameteriv      oglApis.fps.glPointParameteriv_
#define glFogCoordf             oglApis.fps.glFogCoordf_
#define glFogCoordfv            oglApis.fps.glFogCoordfv_
#define glFogCoordd             oglApis.fps.glFogCoordd_
#define glFogCoorddv            oglApis.fps.glFogCoorddv_
#define glFogCoordPointer       oglApis.fps.glFogCoordPointer_
#define glSecondaryColor3b      oglApis.fps.glSecondaryColor3b_
#define glSecondaryColor3bv     oglApis.fps.glSecondaryColor3bv_
#define glSecondaryColor3d      oglApis.fps.glSecondaryColor3d_
#define glSecondaryColor3dv     oglApis.fps.glSecondaryColor3dv_
#define glSecondaryColor3f      oglApis.fps.glSecondaryColor3f_
#define glSecondaryColor3fv     oglApis.fps.glSecondaryColor3fv_
#define glSecondaryColor3i      oglApis.fps.glSecondaryColor3i_
#define glSecondaryColor3iv     oglApis.fps.glSecondaryColor3iv_
#define glSecondaryColor3s      oglApis.fps.glSecondaryColor3s_
#define glSecondaryColor3sv     oglApis.fps.glSecondaryColor3sv_
#define glSecondaryColor3ub     oglApis.fps.glSecondaryColor3ub_
#define glSecondaryColor3ubv    oglApis.fps.glSecondaryColor3ubv_
#define glSecondaryColor3ui     oglApis.fps.glSecondaryColor3ui_
#define glSecondaryColor3uiv    oglApis.fps.glSecondaryColor3uiv_
#define glSecondaryColor3us     oglApis.fps.glSecondaryColor3us_
#define glSecondaryColor3usv    oglApis.fps.glSecondaryColor3usv_
#define glSecondaryColorPointer oglApis.fps.glSecondaryColorPointer_
#define glWindowPos2d           oglApis.fps.glWindowPos2d_
#define glWindowPos2dv          oglApis.fps.glWindowPos2dv_
#define glWindowPos2f           oglApis.fps.glWindowPos2f_
#define glWindowPos2fv          oglApis.fps.glWindowPos2fv_
#define glWindowPos2i           oglApis.fps.glWindowPos2i_
#define glWindowPos2iv          oglApis.fps.glWindowPos2iv_
#define glWindowPos2s           oglApis.fps.glWindowPos2s_
#define glWindowPos2sv          oglApis.fps.glWindowPos2sv_
#define glWindowPos3d           oglApis.fps.glWindowPos3d_
#define glWindowPos3dv          oglApis.fps.glWindowPos3dv_
#define glWindowPos3f           oglApis.fps.glWindowPos3f_
#define glWindowPos3fv          oglApis.fps.glWindowPos3fv_
#define glWindowPos3i           oglApis.fps.glWindowPos3i_
#define glWindowPos3iv          oglApis.fps.glWindowPos3iv_
#define glWindowPos3s           oglApis.fps.glWindowPos3s_
#define glWindowPos3sv          oglApis.fps.glWindowPos3sv_
#define glBlendColor            oglApis.fps.glBlendColor_
#define glBlendEquation         oglApis.fps.glBlendEquation_
#define glGenQueries            oglApis.fps.glGenQueries_
#define glDeleteQueries         oglApis.fps.glDeleteQueries_
#define glIsQuery               oglApis.fps.glIsQuery_
#define glBeginQuery            oglApis.fps.glBeginQuery_
#define glEndQuery              oglApis.fps.glEndQuery_
#define glGetQueryiv            oglApis.fps.glGetQueryiv_
#define glGetQueryObjectiv      oglApis.fps.glGetQueryObjectiv_
#define glGetQueryObjectuiv     oglApis.fps.glGetQueryObjectuiv_
#define glBindBuffer            oglApis.fps.glBindBuffer_
#define glDeleteBuffers         oglApis.fps.glDeleteBuffers_
#define glGenBuffers            oglApis.fps.glGenBuffers_
#define glIsBuffer              oglApis.fps.glIsBuffer_
#define glBufferData            oglApis.fps.glBufferData_
#define glBufferSubData         oglApis.fps.glBufferSubData_
#define glGetBufferSubData      oglApis.fps.glGetBufferSubData_
#define glMapBuffer             oglApis.fps.glMapBuffer_
#define glUnmapBuffer           oglApis.fps.glUnmapBuffer_
#define glGetBufferParameteriv  oglApis.fps.glGetBufferParameteriv_
#define glGetBufferPointerv     oglApis.fps.glGetBufferPointerv_
#define glBlendEquationSeparate oglApis.fps.glBlendEquationSeparate_
#define glDrawBuffers           oglApis.fps.glDrawBuffers_
#define glStencilOpSeparate     oglApis.fps.glStencilOpSeparate_
#define glStencilFuncSeparate   oglApis.fps.glStencilFuncSeparate_
#define glStencilMaskSeparate   oglApis.fps.glStencilMaskSeparate_
#define glAttachShader          oglApis.fps.glAttachShader_
#define glBindAttribLocation    oglApis.fps.glBindAttribLocation_
#define glCompileShader         oglApis.fps.glCompileShader_
#define glCreateProgram         oglApis.fps.glCreateProgram_
#define glCreateShader          oglApis.fps.glCreateShader_
#define glDeleteProgram         oglApis.fps.glDeleteProgram_
#define glDeleteShader          oglApis.fps.glDeleteShader_
#define glDetachShader          oglApis.fps.glDetachShader_
#define glDisableVertexAttribArray oglApis.fps.glDisableVertexAttribArray_
#define glEnableVertexAttribArray oglApis.fps.glEnableVertexAttribArray_
#define glGetActiveAttrib       oglApis.fps.glGetActiveAttrib_
#define glGetActiveUniform      oglApis.fps.glGetActiveUniform_
#define glGetAttachedShaders    oglApis.fps.glGetAttachedShaders_
#define glGetAttribLocation     oglApis.fps.glGetAttribLocation_
#define glGetProgramiv          oglApis.fps.glGetProgramiv_
#define glGetProgramInfoLog     oglApis.fps.glGetProgramInfoLog_
#define glGetShaderiv           oglApis.fps.glGetShaderiv_
#define glGetShaderInfoLog      oglApis.fps.glGetShaderInfoLog_
#define glGetShaderSource       oglApis.fps.glGetShaderSource_
#define glGetUniformLocation    oglApis.fps.glGetUniformLocation_
#define glGetUniformfv          oglApis.fps.glGetUniformfv_
#define glGetUniformiv          oglApis.fps.glGetUniformiv_
#define glGetVertexAttribdv     oglApis.fps.glGetVertexAttribdv_
#define glGetVertexAttribfv     oglApis.fps.glGetVertexAttribfv_
#define glGetVertexAttribiv     oglApis.fps.glGetVertexAttribiv_
#define glGetVertexAttribPointerv oglApis.fps.glGetVertexAttribPointerv_
#define glIsProgram             oglApis.fps.glIsProgram_
#define glIsShader              oglApis.fps.glIsShader_
#define glLinkProgram           oglApis.fps.glLinkProgram_
#define glShaderSource          oglApis.fps.glShaderSource_
#define glUseProgram            oglApis.fps.glUseProgram_
#define glUniform1f             oglApis.fps.glUniform1f_
#define glUniform2f             oglApis.fps.glUniform2f_
#define glUniform3f             oglApis.fps.glUniform3f_
#define glUniform4f             oglApis.fps.glUniform4f_
#define glUniform1i             oglApis.fps.glUniform1i_
#define glUniform2i             oglApis.fps.glUniform2i_
#define glUniform3i             oglApis.fps.glUniform3i_
#define glUniform4i             oglApis.fps.glUniform4i_
#define glUniform1fv            oglApis.fps.glUniform1fv_
#define glUniform2fv            oglApis.fps.glUniform2fv_
#define glUniform3fv            oglApis.fps.glUniform3fv_
#define glUniform4fv            oglApis.fps.glUniform4fv_
#define glUniform1iv            oglApis.fps.glUniform1iv_
#define glUniform2iv            oglApis.fps.glUniform2iv_
#define glUniform3iv            oglApis.fps.glUniform3iv_
#define glUniform4iv            oglApis.fps.glUniform4iv_
#define glUniformMatrix2fv      oglApis.fps.glUniformMatrix2fv_
#define glUniformMatrix3fv      oglApis.fps.glUniformMatrix3fv_
#define glUniformMatrix4fv      oglApis.fps.glUniformMatrix4fv_
#define glValidateProgram       oglApis.fps.glValidateProgram_
#define glVertexAttrib1d        oglApis.fps.glVertexAttrib1d_
#define glVertexAttrib1dv       oglApis.fps.glVertexAttrib1dv_
#define glVertexAttrib1f        oglApis.fps.glVertexAttrib1f_
#define glVertexAttrib1fv       oglApis.fps.glVertexAttrib1fv_
#define glVertexAttrib1s        oglApis.fps.glVertexAttrib1s_
#define glVertexAttrib1sv       oglApis.fps.glVertexAttrib1sv_
#define glVertexAttrib2d        oglApis.fps.glVertexAttrib2d_
#define glVertexAttrib2dv       oglApis.fps.glVertexAttrib2dv_
#define glVertexAttrib2f        oglApis.fps.glVertexAttrib2f_
#define glVertexAttrib2fv       oglApis.fps.glVertexAttrib2fv_
#define glVertexAttrib2s        oglApis.fps.glVertexAttrib2s_
#define glVertexAttrib2sv       oglApis.fps.glVertexAttrib2sv_
#define glVertexAttrib3d        oglApis.fps.glVertexAttrib3d_
#define glVertexAttrib3dv       oglApis.fps.glVertexAttrib3dv_
#define glVertexAttrib3f        oglApis.fps.glVertexAttrib3f_
#define glVertexAttrib3fv       oglApis.fps.glVertexAttrib3fv_
#define glVertexAttrib3s        oglApis.fps.glVertexAttrib3s_
#define glVertexAttrib3sv       oglApis.fps.glVertexAttrib3sv_
#define glVertexAttrib4Nbv      oglApis.fps.glVertexAttrib4Nbv_
#define glVertexAttrib4Niv      oglApis.fps.glVertexAttrib4Niv_
#define glVertexAttrib4Nsv      oglApis.fps.glVertexAttrib4Nsv_
#define glVertexAttrib4Nub      oglApis.fps.glVertexAttrib4Nub_
#define glVertexAttrib4Nubv     oglApis.fps.glVertexAttrib4Nubv_
#define glVertexAttrib4Nuiv     oglApis.fps.glVertexAttrib4Nuiv_
#define glVertexAttrib4Nusv     oglApis.fps.glVertexAttrib4Nusv_
#define glVertexAttrib4bv       oglApis.fps.glVertexAttrib4bv_
#define glVertexAttrib4d        oglApis.fps.glVertexAttrib4d_
#define glVertexAttrib4dv       oglApis.fps.glVertexAttrib4dv_
#define glVertexAttrib4f        oglApis.fps.glVertexAttrib4f_
#define glVertexAttrib4fv       oglApis.fps.glVertexAttrib4fv_
#define glVertexAttrib4iv       oglApis.fps.glVertexAttrib4iv_
#define glVertexAttrib4s        oglApis.fps.glVertexAttrib4s_
#define glVertexAttrib4sv       oglApis.fps.glVertexAttrib4sv_
#define glVertexAttrib4ubv      oglApis.fps.glVertexAttrib4ubv_
#define glVertexAttrib4uiv      oglApis.fps.glVertexAttrib4uiv_
#define glVertexAttrib4usv      oglApis.fps.glVertexAttrib4usv_
#define glVertexAttribPointer   oglApis.fps.glVertexAttribPointer_

GL_NS_END

#endif /* LOADGL_GL_VERSION_2_0_GENERATED_H */


#if defined(LOADGL_IMPLEMENTATION) && !defined(loadgl_implemented)
#define loadgl_implemented


#include <string.h>
#include <stdlib.h>


#ifdef __APPLE__

#include <dlfcn.h>

static void *loadgl_GetProcAddress (const char *name) {
    static void* image = NULL;
    if (image == NULL)
        image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL",
                RTLD_LAZY);
    return image ? dlsym(image, name) : NULL;
}

#elif defined(__sgi) || defined(__sun)

#include <dlfcn.h>
#include <stdio.h>

static void* loadgl_GetProcAddress (const char* name) {
  static void* h = NULL;
  static void* gpa;

  if (h == NULL) {
    if ((h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL)) == NULL)
       return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void*(*)(const GLubyte*))gpa)((const GLubyte*)name);
  else
    return dlsym(h, name);
}

#elif defined(__WIN32)

#ifdef _MSC_VER
#pragma warning(disable: 4055)
#pragma warning(disable: 4054)
#endif

static int loadgl_TestPointer(const PROC pTest) {
  ptrdiff_t iTest;
  if(!pTest) return 0;
  iTest = (ptrdiff_t)pTest;
  return iTest != 1 && iTest != 2 && iTest != 3 && iTest != -1;
}

static PROC loadgl_GetProcAddress(const char *name) {
  HMODULE glMod = NULL;
  PROC pFunc = wglGetProcAddress((LPCSTR)name);
  if(loadgl_TestPointer(pFunc))
    return pFunc;
  glMod = GetModuleHandleA("OpenGL32.dll");
  return (PROC)GetProcAddress(glMod, (LPCSTR)name);
}

#else

#include <GL/glx.h>

#define loadgl_GetProcAddress(name) \
      ((*glXGetProcAddressARB)((const GLubyte*)name))

#endif


GL_NS_BEGIN

/* OpenGL routines load */

LOADGL_API LoadGLapis oglApis;

static int loadgl_loaded_count = 0;

static int loadgl_LoadFunctions(void) {
  const char *commands[] = {
    "glCullFace",
    "glFrontFace",
    "glHint",
    "glLineWidth",
    "glPointSize",
    "glPolygonMode",
    "glScissor",
    "glTexParameterf",
    "glTexParameterfv",
    "glTexParameteri",
    "glTexParameteriv",
    "glTexImage1D",
    "glTexImage2D",
    "glDrawBuffer",
    "glClear",
    "glClearColor",
    "glClearStencil",
    "glClearDepth",
    "glStencilMask",
    "glColorMask",
    "glDepthMask",
    "glDisable",
    "glEnable",
    "glFinish",
    "glFlush",
    "glBlendFunc",
    "glLogicOp",
    "glStencilFunc",
    "glStencilOp",
    "glDepthFunc",
    "glPixelStoref",
    "glPixelStorei",
    "glReadBuffer",
    "glReadPixels",
    "glGetBooleanv",
    "glGetDoublev",
    "glGetError",
    "glGetFloatv",
    "glGetIntegerv",
    "glGetString",
    "glGetTexImage",
    "glGetTexParameterfv",
    "glGetTexParameteriv",
    "glGetTexLevelParameterfv",
    "glGetTexLevelParameteriv",
    "glIsEnabled",
    "glDepthRange",
    "glViewport",
    "glNewList",
    "glEndList",
    "glCallList",
    "glCallLists",
    "glDeleteLists",
    "glGenLists",
    "glListBase",
    "glBegin",
    "glBitmap",
    "glColor3b",
    "glColor3bv",
    "glColor3d",
    "glColor3dv",
    "glColor3f",
    "glColor3fv",
    "glColor3i",
    "glColor3iv",
    "glColor3s",
    "glColor3sv",
    "glColor3ub",
    "glColor3ubv",
    "glColor3ui",
    "glColor3uiv",
    "glColor3us",
    "glColor3usv",
    "glColor4b",
    "glColor4bv",
    "glColor4d",
    "glColor4dv",
    "glColor4f",
    "glColor4fv",
    "glColor4i",
    "glColor4iv",
    "glColor4s",
    "glColor4sv",
    "glColor4ub",
    "glColor4ubv",
    "glColor4ui",
    "glColor4uiv",
    "glColor4us",
    "glColor4usv",
    "glEdgeFlag",
    "glEdgeFlagv",
    "glEnd",
    "glIndexd",
    "glIndexdv",
    "glIndexf",
    "glIndexfv",
    "glIndexi",
    "glIndexiv",
    "glIndexs",
    "glIndexsv",
    "glNormal3b",
    "glNormal3bv",
    "glNormal3d",
    "glNormal3dv",
    "glNormal3f",
    "glNormal3fv",
    "glNormal3i",
    "glNormal3iv",
    "glNormal3s",
    "glNormal3sv",
    "glRasterPos2d",
    "glRasterPos2dv",
    "glRasterPos2f",
    "glRasterPos2fv",
    "glRasterPos2i",
    "glRasterPos2iv",
    "glRasterPos2s",
    "glRasterPos2sv",
    "glRasterPos3d",
    "glRasterPos3dv",
    "glRasterPos3f",
    "glRasterPos3fv",
    "glRasterPos3i",
    "glRasterPos3iv",
    "glRasterPos3s",
    "glRasterPos3sv",
    "glRasterPos4d",
    "glRasterPos4dv",
    "glRasterPos4f",
    "glRasterPos4fv",
    "glRasterPos4i",
    "glRasterPos4iv",
    "glRasterPos4s",
    "glRasterPos4sv",
    "glRectd",
    "glRectdv",
    "glRectf",
    "glRectfv",
    "glRecti",
    "glRectiv",
    "glRects",
    "glRectsv",
    "glTexCoord1d",
    "glTexCoord1dv",
    "glTexCoord1f",
    "glTexCoord1fv",
    "glTexCoord1i",
    "glTexCoord1iv",
    "glTexCoord1s",
    "glTexCoord1sv",
    "glTexCoord2d",
    "glTexCoord2dv",
    "glTexCoord2f",
    "glTexCoord2fv",
    "glTexCoord2i",
    "glTexCoord2iv",
    "glTexCoord2s",
    "glTexCoord2sv",
    "glTexCoord3d",
    "glTexCoord3dv",
    "glTexCoord3f",
    "glTexCoord3fv",
    "glTexCoord3i",
    "glTexCoord3iv",
    "glTexCoord3s",
    "glTexCoord3sv",
    "glTexCoord4d",
    "glTexCoord4dv",
    "glTexCoord4f",
    "glTexCoord4fv",
    "glTexCoord4i",
    "glTexCoord4iv",
    "glTexCoord4s",
    "glTexCoord4sv",
    "glVertex2d",
    "glVertex2dv",
    "glVertex2f",
    "glVertex2fv",
    "glVertex2i",
    "glVertex2iv",
    "glVertex2s",
    "glVertex2sv",
    "glVertex3d",
    "glVertex3dv",
    "glVertex3f",
    "glVertex3fv",
    "glVertex3i",
    "glVertex3iv",
    "glVertex3s",
    "glVertex3sv",
    "glVertex4d",
    "glVertex4dv",
    "glVertex4f",
    "glVertex4fv",
    "glVertex4i",
    "glVertex4iv",
    "glVertex4s",
    "glVertex4sv",
    "glClipPlane",
    "glColorMaterial",
    "glFogf",
    "glFogfv",
    "glFogi",
    "glFogiv",
    "glLightf",
    "glLightfv",
    "glLighti",
    "glLightiv",
    "glLightModelf",
    "glLightModelfv",
    "glLightModeli",
    "glLightModeliv",
    "glLineStipple",
    "glMaterialf",
    "glMaterialfv",
    "glMateriali",
    "glMaterialiv",
    "glPolygonStipple",
    "glShadeModel",
    "glTexEnvf",
    "glTexEnvfv",
    "glTexEnvi",
    "glTexEnviv",
    "glTexGend",
    "glTexGendv",
    "glTexGenf",
    "glTexGenfv",
    "glTexGeni",
    "glTexGeniv",
    "glFeedbackBuffer",
    "glSelectBuffer",
    "glRenderMode",
    "glInitNames",
    "glLoadName",
    "glPassThrough",
    "glPopName",
    "glPushName",
    "glClearAccum",
    "glClearIndex",
    "glIndexMask",
    "glAccum",
    "glPopAttrib",
    "glPushAttrib",
    "glMap1d",
    "glMap1f",
    "glMap2d",
    "glMap2f",
    "glMapGrid1d",
    "glMapGrid1f",
    "glMapGrid2d",
    "glMapGrid2f",
    "glEvalCoord1d",
    "glEvalCoord1dv",
    "glEvalCoord1f",
    "glEvalCoord1fv",
    "glEvalCoord2d",
    "glEvalCoord2dv",
    "glEvalCoord2f",
    "glEvalCoord2fv",
    "glEvalMesh1",
    "glEvalPoint1",
    "glEvalMesh2",
    "glEvalPoint2",
    "glAlphaFunc",
    "glPixelZoom",
    "glPixelTransferf",
    "glPixelTransferi",
    "glPixelMapfv",
    "glPixelMapuiv",
    "glPixelMapusv",
    "glCopyPixels",
    "glDrawPixels",
    "glGetClipPlane",
    "glGetLightfv",
    "glGetLightiv",
    "glGetMapdv",
    "glGetMapfv",
    "glGetMapiv",
    "glGetMaterialfv",
    "glGetMaterialiv",
    "glGetPixelMapfv",
    "glGetPixelMapuiv",
    "glGetPixelMapusv",
    "glGetPolygonStipple",
    "glGetTexEnvfv",
    "glGetTexEnviv",
    "glGetTexGendv",
    "glGetTexGenfv",
    "glGetTexGeniv",
    "glIsList",
    "glFrustum",
    "glLoadIdentity",
    "glLoadMatrixf",
    "glLoadMatrixd",
    "glMatrixMode",
    "glMultMatrixf",
    "glMultMatrixd",
    "glOrtho",
    "glPopMatrix",
    "glPushMatrix",
    "glRotated",
    "glRotatef",
    "glScaled",
    "glScalef",
    "glTranslated",
    "glTranslatef",
    "glDrawArrays",
    "glDrawElements",
    "glGetPointerv",
    "glPolygonOffset",
    "glCopyTexImage1D",
    "glCopyTexImage2D",
    "glCopyTexSubImage1D",
    "glCopyTexSubImage2D",
    "glTexSubImage1D",
    "glTexSubImage2D",
    "glBindTexture",
    "glDeleteTextures",
    "glGenTextures",
    "glIsTexture",
    "glArrayElement",
    "glColorPointer",
    "glDisableClientState",
    "glEdgeFlagPointer",
    "glEnableClientState",
    "glIndexPointer",
    "glInterleavedArrays",
    "glNormalPointer",
    "glTexCoordPointer",
    "glVertexPointer",
    "glAreTexturesResident",
    "glPrioritizeTextures",
    "glIndexub",
    "glIndexubv",
    "glPopClientAttrib",
    "glPushClientAttrib",
    "glDrawRangeElements",
    "glTexImage3D",
    "glTexSubImage3D",
    "glCopyTexSubImage3D",
    "glActiveTexture",
    "glSampleCoverage",
    "glCompressedTexImage3D",
    "glCompressedTexImage2D",
    "glCompressedTexImage1D",
    "glCompressedTexSubImage3D",
    "glCompressedTexSubImage2D",
    "glCompressedTexSubImage1D",
    "glGetCompressedTexImage",
    "glClientActiveTexture",
    "glMultiTexCoord1d",
    "glMultiTexCoord1dv",
    "glMultiTexCoord1f",
    "glMultiTexCoord1fv",
    "glMultiTexCoord1i",
    "glMultiTexCoord1iv",
    "glMultiTexCoord1s",
    "glMultiTexCoord1sv",
    "glMultiTexCoord2d",
    "glMultiTexCoord2dv",
    "glMultiTexCoord2f",
    "glMultiTexCoord2fv",
    "glMultiTexCoord2i",
    "glMultiTexCoord2iv",
    "glMultiTexCoord2s",
    "glMultiTexCoord2sv",
    "glMultiTexCoord3d",
    "glMultiTexCoord3dv",
    "glMultiTexCoord3f",
    "glMultiTexCoord3fv",
    "glMultiTexCoord3i",
    "glMultiTexCoord3iv",
    "glMultiTexCoord3s",
    "glMultiTexCoord3sv",
    "glMultiTexCoord4d",
    "glMultiTexCoord4dv",
    "glMultiTexCoord4f",
    "glMultiTexCoord4fv",
    "glMultiTexCoord4i",
    "glMultiTexCoord4iv",
    "glMultiTexCoord4s",
    "glMultiTexCoord4sv",
    "glLoadTransposeMatrixf",
    "glLoadTransposeMatrixd",
    "glMultTransposeMatrixf",
    "glMultTransposeMatrixd",
    "glBlendFuncSeparate",
    "glMultiDrawArrays",
    "glMultiDrawElements",
    "glPointParameterf",
    "glPointParameterfv",
    "glPointParameteri",
    "glPointParameteriv",
    "glFogCoordf",
    "glFogCoordfv",
    "glFogCoordd",
    "glFogCoorddv",
    "glFogCoordPointer",
    "glSecondaryColor3b",
    "glSecondaryColor3bv",
    "glSecondaryColor3d",
    "glSecondaryColor3dv",
    "glSecondaryColor3f",
    "glSecondaryColor3fv",
    "glSecondaryColor3i",
    "glSecondaryColor3iv",
    "glSecondaryColor3s",
    "glSecondaryColor3sv",
    "glSecondaryColor3ub",
    "glSecondaryColor3ubv",
    "glSecondaryColor3ui",
    "glSecondaryColor3uiv",
    "glSecondaryColor3us",
    "glSecondaryColor3usv",
    "glSecondaryColorPointer",
    "glWindowPos2d",
    "glWindowPos2dv",
    "glWindowPos2f",
    "glWindowPos2fv",
    "glWindowPos2i",
    "glWindowPos2iv",
    "glWindowPos2s",
    "glWindowPos2sv",
    "glWindowPos3d",
    "glWindowPos3dv",
    "glWindowPos3f",
    "glWindowPos3fv",
    "glWindowPos3i",
    "glWindowPos3iv",
    "glWindowPos3s",
    "glWindowPos3sv",
    "glBlendColor",
    "glBlendEquation",
    "glGenQueries",
    "glDeleteQueries",
    "glIsQuery",
    "glBeginQuery",
    "glEndQuery",
    "glGetQueryiv",
    "glGetQueryObjectiv",
    "glGetQueryObjectuiv",
    "glBindBuffer",
    "glDeleteBuffers",
    "glGenBuffers",
    "glIsBuffer",
    "glBufferData",
    "glBufferSubData",
    "glGetBufferSubData",
    "glMapBuffer",
    "glUnmapBuffer",
    "glGetBufferParameteriv",
    "glGetBufferPointerv",
    "glBlendEquationSeparate",
    "glDrawBuffers",
    "glStencilOpSeparate",
    "glStencilFuncSeparate",
    "glStencilMaskSeparate",
    "glAttachShader",
    "glBindAttribLocation",
    "glCompileShader",
    "glCreateProgram",
    "glCreateShader",
    "glDeleteProgram",
    "glDeleteShader",
    "glDetachShader",
    "glDisableVertexAttribArray",
    "glEnableVertexAttribArray",
    "glGetActiveAttrib",
    "glGetActiveUniform",
    "glGetAttachedShaders",
    "glGetAttribLocation",
    "glGetProgramiv",
    "glGetProgramInfoLog",
    "glGetShaderiv",
    "glGetShaderInfoLog",
    "glGetShaderSource",
    "glGetUniformLocation",
    "glGetUniformfv",
    "glGetUniformiv",
    "glGetVertexAttribdv",
    "glGetVertexAttribfv",
    "glGetVertexAttribiv",
    "glGetVertexAttribPointerv",
    "glIsProgram",
    "glIsShader",
    "glLinkProgram",
    "glShaderSource",
    "glUseProgram",
    "glUniform1f",
    "glUniform2f",
    "glUniform3f",
    "glUniform4f",
    "glUniform1i",
    "glUniform2i",
    "glUniform3i",
    "glUniform4i",
    "glUniform1fv",
    "glUniform2fv",
    "glUniform3fv",
    "glUniform4fv",
    "glUniform1iv",
    "glUniform2iv",
    "glUniform3iv",
    "glUniform4iv",
    "glUniformMatrix2fv",
    "glUniformMatrix3fv",
    "glUniformMatrix4fv",
    "glValidateProgram",
    "glVertexAttrib1d",
    "glVertexAttrib1dv",
    "glVertexAttrib1f",
    "glVertexAttrib1fv",
    "glVertexAttrib1s",
    "glVertexAttrib1sv",
    "glVertexAttrib2d",
    "glVertexAttrib2dv",
    "glVertexAttrib2f",
    "glVertexAttrib2fv",
    "glVertexAttrib2s",
    "glVertexAttrib2sv",
    "glVertexAttrib3d",
    "glVertexAttrib3dv",
    "glVertexAttrib3f",
    "glVertexAttrib3fv",
    "glVertexAttrib3s",
    "glVertexAttrib3sv",
    "glVertexAttrib4Nbv",
    "glVertexAttrib4Niv",
    "glVertexAttrib4Nsv",
    "glVertexAttrib4Nub",
    "glVertexAttrib4Nubv",
    "glVertexAttrib4Nuiv",
    "glVertexAttrib4Nusv",
    "glVertexAttrib4bv",
    "glVertexAttrib4d",
    "glVertexAttrib4dv",
    "glVertexAttrib4f",
    "glVertexAttrib4fv",
    "glVertexAttrib4iv",
    "glVertexAttrib4s",
    "glVertexAttrib4sv",
    "glVertexAttrib4ubv",
    "glVertexAttrib4uiv",
    "glVertexAttrib4usv",
    "glVertexAttribPointer",
  };
  int i, failed = 0;
  for (i = 0; i < LOADGL_COMMAND_COUNT; ++i) {
    oglApis.arr[i] = (void(APIENTRYP)(void))loadgl_GetProcAddress(commands[i]);
    if (oglApis.arr[i] == NULL)
      ++failed;
   else
      ++loadgl_loaded_count;
  }

  return failed;
}

LOADGL_API int loadgl_Init(void) {
  /* TODO load extensions */

  if (loadgl_loaded_count != LOADGL_COMMAND_COUNT)
    return loadgl_LoadFunctions() == 0;
  return 1;
}

LOADGL_API int loadgl_LoadedCount() {
  return loadgl_loaded_count;
}


/* OpenGL version detect */

static int loadgl_major_version = 0;
static int loadgl_minor_version = 0;

static void loadgl_ParseVersion(int *major, int *minor, const char *s) {
  char *buff, *dot1_pos, *dot2_pos;

  if((dot1_pos = strchr(s, '.')) == NULL)
    return;

  buff = (char*)malloc(strlen(s) + 1);
  if (buff == NULL) return;
  strcpy(buff, s);
  dot1_pos = &buff[dot1_pos-s];

  *dot1_pos = '\0';
  *major = atoi(buff);
  
  /* if no extra data. Take the whole rest of the string. */
  if((dot2_pos = strchr(dot1_pos + 1, ' ')) != NULL)
    *dot2_pos = '\0';

  *minor = atoi(dot1_pos + 1);
  free(buff);
}

static void loadgl_GetGLVersion() {
   if(loadgl_major_version != 0) return;
   loadgl_ParseVersion(
      &loadgl_major_version,
      &loadgl_minor_version,
      (const char*)glGetString(GL_VERSION));
}

LOADGL_API int loadgl_GetMajorVersion() {
  loadgl_GetGLVersion();
  return loadgl_major_version;
}

LOADGL_API int loadgl_GetMinorVersion() {
  loadgl_GetGLVersion();
  return loadgl_minor_version;
}

LOADGL_API int loadgl_IsVersionGEQ(int major, int minor) {
  loadgl_GetGLVersion();
  if(major >  loadgl_major_version) return 1;
  if(major <  loadgl_major_version) return 0;
  if(minor >= loadgl_minor_version) return 1;
  return 0;
}


GL_NS_END

#endif /* LOADGL_IMPLEMENTATION */
