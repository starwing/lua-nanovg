#ifndef LOADGL_GL_ES_VERSION_2_0_GENERATED_H
#define LOADGL_GL_ES_VERSION_2_0_GENERATED_H

#define GL_ES_VERSION_2_0 1

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


#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef unsigned int            GLenum;
typedef unsigned int            GLuint;
typedef char                    GLchar;
typedef float                   GLfloat;
typedef ptrdiff_t               GLsizeiptr;
typedef ptrdiff_t               GLintptr;
typedef unsigned int            GLbitfield;
typedef int                     GLint;
typedef unsigned char           GLboolean;
typedef int                     GLsizei;
typedef unsigned char           GLubyte;


/* OpenGL types */

/* Not used by the API, for compatibility with old gl2.h */

typedef signed char             GLbyte;
typedef float                   GLclampf;
typedef GLint                   GLfixed; /* Must be 32 bits */
typedef short                   GLshort;
typedef unsigned short          GLushort;
typedef void                    GLvoid; /* Not an actual GL type, though used in headers in the past */


typedef struct __GLsync *       GLsync;
typedef int64_t                 GLint64;
typedef uint64_t                GLuint64;


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
#define GL_FUNC_ADD             0x8006
#define GL_BLEND_EQUATION       0x8009
#define GL_BLEND_EQUATION_RGB   0x8009
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_FUNC_SUBTRACT        0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_BLEND_DST_RGB        0x80C8
#define GL_BLEND_SRC_RGB        0x80C9
#define GL_BLEND_DST_ALPHA      0x80CA
#define GL_BLEND_SRC_ALPHA      0x80CB
#define GL_CONSTANT_COLOR       0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA       0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_BLEND_COLOR          0x8005
#define GL_ARRAY_BUFFER         0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_STREAM_DRAW          0x88E0
#define GL_STATIC_DRAW          0x88E4
#define GL_DYNAMIC_DRAW         0x88E8
#define GL_BUFFER_SIZE          0x8764
#define GL_BUFFER_USAGE         0x8765
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_FRONT                0x0404
#define GL_BACK                 0x0405
#define GL_FRONT_AND_BACK       0x0408
#define GL_TEXTURE_2D           0x0DE1
#define GL_CULL_FACE            0x0B44
#define GL_BLEND                0x0BE2
#define GL_DITHER               0x0BD0
#define GL_STENCIL_TEST         0x0B90
#define GL_DEPTH_TEST           0x0B71
#define GL_SCISSOR_TEST         0x0C11
#define GL_POLYGON_OFFSET_FILL  0x8037
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_COVERAGE      0x80A0
#define GL_NO_ERROR             0
#define GL_INVALID_ENUM         0x0500
#define GL_INVALID_VALUE        0x0501
#define GL_INVALID_OPERATION    0x0502
#define GL_OUT_OF_MEMORY        0x0505
#define GL_CW                   0x0900
#define GL_CCW                  0x0901
#define GL_LINE_WIDTH           0x0B21
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_CULL_FACE_MODE       0x0B45
#define GL_FRONT_FACE           0x0B46
#define GL_DEPTH_RANGE          0x0B70
#define GL_DEPTH_WRITEMASK      0x0B72
#define GL_DEPTH_CLEAR_VALUE    0x0B73
#define GL_DEPTH_FUNC           0x0B74
#define GL_STENCIL_CLEAR_VALUE  0x0B91
#define GL_STENCIL_FUNC         0x0B92
#define GL_STENCIL_FAIL         0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF          0x0B97
#define GL_STENCIL_VALUE_MASK   0x0B93
#define GL_STENCIL_WRITEMASK    0x0B98
#define GL_STENCIL_BACK_FUNC    0x8800
#define GL_STENCIL_BACK_FAIL    0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_STENCIL_BACK_REF     0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_VIEWPORT             0x0BA2
#define GL_SCISSOR_BOX          0x0C10
#define GL_COLOR_CLEAR_VALUE    0x0C22
#define GL_COLOR_WRITEMASK      0x0C23
#define GL_UNPACK_ALIGNMENT     0x0CF5
#define GL_PACK_ALIGNMENT       0x0D05
#define GL_MAX_TEXTURE_SIZE     0x0D33
#define GL_MAX_VIEWPORT_DIMS    0x0D3A
#define GL_SUBPIXEL_BITS        0x0D50
#define GL_RED_BITS             0x0D52
#define GL_GREEN_BITS           0x0D53
#define GL_BLUE_BITS            0x0D54
#define GL_ALPHA_BITS           0x0D55
#define GL_DEPTH_BITS           0x0D56
#define GL_STENCIL_BITS         0x0D57
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_2D   0x8069
#define GL_SAMPLE_BUFFERS       0x80A8
#define GL_SAMPLES              0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_DONT_CARE            0x1100
#define GL_FASTEST              0x1101
#define GL_NICEST               0x1102
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_BYTE                 0x1400
#define GL_UNSIGNED_BYTE        0x1401
#define GL_SHORT                0x1402
#define GL_UNSIGNED_SHORT       0x1403
#define GL_INT                  0x1404
#define GL_UNSIGNED_INT         0x1405
#define GL_FLOAT                0x1406
#define GL_FIXED                0x140C
#define GL_DEPTH_COMPONENT      0x1902
#define GL_ALPHA                0x1906
#define GL_RGB                  0x1907
#define GL_RGBA                 0x1908
#define GL_LUMINANCE            0x1909
#define GL_LUMINANCE_ALPHA      0x190A
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_FRAGMENT_SHADER      0x8B30
#define GL_VERTEX_SHADER        0x8B31
#define GL_MAX_VERTEX_ATTRIBS   0x8869
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MAX_VARYING_VECTORS  0x8DFC
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_SHADER_TYPE          0x8B4F
#define GL_DELETE_STATUS        0x8B80
#define GL_LINK_STATUS          0x8B82
#define GL_VALIDATE_STATUS      0x8B83
#define GL_ATTACHED_SHADERS     0x8B85
#define GL_ACTIVE_UNIFORMS      0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_ACTIVE_ATTRIBUTES    0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM      0x8B8D
#define GL_NEVER                0x0200
#define GL_LESS                 0x0201
#define GL_EQUAL                0x0202
#define GL_LEQUAL               0x0203
#define GL_GREATER              0x0204
#define GL_NOTEQUAL             0x0205
#define GL_GEQUAL               0x0206
#define GL_ALWAYS               0x0207
#define GL_KEEP                 0x1E00
#define GL_REPLACE              0x1E01
#define GL_INCR                 0x1E02
#define GL_DECR                 0x1E03
#define GL_INVERT               0x150A
#define GL_INCR_WRAP            0x8507
#define GL_DECR_WRAP            0x8508
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
#define GL_TEXTURE              0x1702
#define GL_TEXTURE_CUBE_MAP     0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
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
#define GL_REPEAT               0x2901
#define GL_CLAMP_TO_EDGE        0x812F
#define GL_MIRRORED_REPEAT      0x8370
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
#define GL_SAMPLER_2D           0x8B5E
#define GL_SAMPLER_CUBE         0x8B60
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_COMPILE_STATUS       0x8B81
#define GL_INFO_LOG_LENGTH      0x8B84
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_SHADER_COMPILER      0x8DFA
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_LOW_FLOAT            0x8DF0
#define GL_MEDIUM_FLOAT         0x8DF1
#define GL_HIGH_FLOAT           0x8DF2
#define GL_LOW_INT              0x8DF3
#define GL_MEDIUM_INT           0x8DF4
#define GL_HIGH_INT             0x8DF5
#define GL_FRAMEBUFFER          0x8D40
#define GL_RENDERBUFFER         0x8D41
#define GL_RGBA4                0x8056
#define GL_RGB5_A1              0x8057
#define GL_RGB565               0x8D62
#define GL_DEPTH_COMPONENT16    0x81A5
#define GL_STENCIL_INDEX8       0x8D48
#define GL_RENDERBUFFER_WIDTH   0x8D42
#define GL_RENDERBUFFER_HEIGHT  0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_COLOR_ATTACHMENT0    0x8CE0
#define GL_DEPTH_ATTACHMENT     0x8D00
#define GL_STENCIL_ATTACHMENT   0x8D20
#define GL_NONE                 0
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS 0x8CD9
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_FRAMEBUFFER_BINDING  0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506


/* OpenGL commands */

#define LOADGL_COMMAND_COUNT 142

typedef union LoadGLapis {
  void (APIENTRYP arr[LOADGL_COMMAND_COUNT]) (void);
  struct {
    void (APIENTRYP glActiveTexture_) (GLenum texture);
    void (APIENTRYP glAttachShader_) (GLuint program, GLuint shader);
    void (APIENTRYP glBindAttribLocation_) (GLuint program, GLuint index, const  GLchar  * name);
    void (APIENTRYP glBindBuffer_) (GLenum target, GLuint buffer);
    void (APIENTRYP glBindFramebuffer_) (GLenum target, GLuint framebuffer);
    void (APIENTRYP glBindRenderbuffer_) (GLenum target, GLuint renderbuffer);
    void (APIENTRYP glBindTexture_) (GLenum target, GLuint texture);
    void (APIENTRYP glBlendColor_) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void (APIENTRYP glBlendEquation_) (GLenum mode);
    void (APIENTRYP glBlendEquationSeparate_) (GLenum modeRGB, GLenum modeAlpha);
    void (APIENTRYP glBlendFunc_) (GLenum sfactor, GLenum dfactor);
    void (APIENTRYP glBlendFuncSeparate_) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    void (APIENTRYP glBufferData_) (GLenum target, GLsizeiptr size, const void * data, GLenum usage);
    void (APIENTRYP glBufferSubData_) (GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
    GLenum (APIENTRYP glCheckFramebufferStatus_) (GLenum target);
    void (APIENTRYP glClear_) (GLbitfield mask);
    void (APIENTRYP glClearColor_) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void (APIENTRYP glClearDepthf_) (GLfloat d);
    void (APIENTRYP glClearStencil_) (GLint s);
    void (APIENTRYP glColorMask_) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    void (APIENTRYP glCompileShader_) (GLuint shader);
    void (APIENTRYP glCompressedTexImage2D_) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
    void (APIENTRYP glCompressedTexSubImage2D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
    void (APIENTRYP glCopyTexImage2D_) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    void (APIENTRYP glCopyTexSubImage2D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLuint (APIENTRYP glCreateProgram_) (void);
    GLuint (APIENTRYP glCreateShader_) (GLenum type);
    void (APIENTRYP glCullFace_) (GLenum mode);
    void (APIENTRYP glDeleteBuffers_) (GLsizei n, const  GLuint  * buffers);
    void (APIENTRYP glDeleteFramebuffers_) (GLsizei n, const  GLuint  * framebuffers);
    void (APIENTRYP glDeleteProgram_) (GLuint program);
    void (APIENTRYP glDeleteRenderbuffers_) (GLsizei n, const  GLuint  * renderbuffers);
    void (APIENTRYP glDeleteShader_) (GLuint shader);
    void (APIENTRYP glDeleteTextures_) (GLsizei n, const  GLuint  * textures);
    void (APIENTRYP glDepthFunc_) (GLenum func);
    void (APIENTRYP glDepthMask_) (GLboolean flag);
    void (APIENTRYP glDepthRangef_) (GLfloat n, GLfloat f);
    void (APIENTRYP glDetachShader_) (GLuint program, GLuint shader);
    void (APIENTRYP glDisable_) (GLenum cap);
    void (APIENTRYP glDisableVertexAttribArray_) (GLuint index);
    void (APIENTRYP glDrawArrays_) (GLenum mode, GLint first, GLsizei count);
    void (APIENTRYP glDrawElements_) (GLenum mode, GLsizei count, GLenum type, const void * indices);
    void (APIENTRYP glEnable_) (GLenum cap);
    void (APIENTRYP glEnableVertexAttribArray_) (GLuint index);
    void (APIENTRYP glFinish_) (void);
    void (APIENTRYP glFlush_) (void);
    void (APIENTRYP glFramebufferRenderbuffer_) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    void (APIENTRYP glFramebufferTexture2D_) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    void (APIENTRYP glFrontFace_) (GLenum mode);
    void (APIENTRYP glGenBuffers_) (GLsizei n, GLuint  * buffers);
    void (APIENTRYP glGenerateMipmap_) (GLenum target);
    void (APIENTRYP glGenFramebuffers_) (GLsizei n, GLuint  * framebuffers);
    void (APIENTRYP glGenRenderbuffers_) (GLsizei n, GLuint  * renderbuffers);
    void (APIENTRYP glGenTextures_) (GLsizei n, GLuint  * textures);
    void (APIENTRYP glGetActiveAttrib_) (GLuint program, GLuint index, GLsizei bufSize, GLsizei  * length, GLint  * size, GLenum  * type, GLchar  * name);
    void (APIENTRYP glGetActiveUniform_) (GLuint program, GLuint index, GLsizei bufSize, GLsizei  * length, GLint  * size, GLenum  * type, GLchar  * name);
    void (APIENTRYP glGetAttachedShaders_) (GLuint program, GLsizei maxCount, GLsizei  * count, GLuint  * shaders);
    GLint (APIENTRYP glGetAttribLocation_) (GLuint program, const  GLchar  * name);
    void (APIENTRYP glGetBooleanv_) (GLenum pname, GLboolean  * data);
    void (APIENTRYP glGetBufferParameteriv_) (GLenum target, GLenum pname, GLint  * params);
    GLenum (APIENTRYP glGetError_) (void);
    void (APIENTRYP glGetFloatv_) (GLenum pname, GLfloat  * data);
    void (APIENTRYP glGetFramebufferAttachmentParameteriv_) (GLenum target, GLenum attachment, GLenum pname, GLint  * params);
    void (APIENTRYP glGetIntegerv_) (GLenum pname, GLint  * data);
    void (APIENTRYP glGetProgramiv_) (GLuint program, GLenum pname, GLint  * params);
    void (APIENTRYP glGetProgramInfoLog_) (GLuint program, GLsizei bufSize, GLsizei  * length, GLchar  * infoLog);
    void (APIENTRYP glGetRenderbufferParameteriv_) (GLenum target, GLenum pname, GLint  * params);
    void (APIENTRYP glGetShaderiv_) (GLuint shader, GLenum pname, GLint  * params);
    void (APIENTRYP glGetShaderInfoLog_) (GLuint shader, GLsizei bufSize, GLsizei  * length, GLchar  * infoLog);
    void (APIENTRYP glGetShaderPrecisionFormat_) (GLenum shadertype, GLenum precisiontype, GLint  * range, GLint  * precision);
    void (APIENTRYP glGetShaderSource_) (GLuint shader, GLsizei bufSize, GLsizei  * length, GLchar  * source);
    const GLubyte * (APIENTRYP glGetString_) (GLenum name);
    void (APIENTRYP glGetTexParameterfv_) (GLenum target, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetTexParameteriv_) (GLenum target, GLenum pname, GLint  * params);
    void (APIENTRYP glGetUniformfv_) (GLuint program, GLint location, GLfloat  * params);
    void (APIENTRYP glGetUniformiv_) (GLuint program, GLint location, GLint  * params);
    GLint (APIENTRYP glGetUniformLocation_) (GLuint program, const  GLchar  * name);
    void (APIENTRYP glGetVertexAttribfv_) (GLuint index, GLenum pname, GLfloat  * params);
    void (APIENTRYP glGetVertexAttribiv_) (GLuint index, GLenum pname, GLint  * params);
    void (APIENTRYP glGetVertexAttribPointerv_) (GLuint index, GLenum pname, void ** pointer);
    void (APIENTRYP glHint_) (GLenum target, GLenum mode);
    GLboolean (APIENTRYP glIsBuffer_) (GLuint buffer);
    GLboolean (APIENTRYP glIsEnabled_) (GLenum cap);
    GLboolean (APIENTRYP glIsFramebuffer_) (GLuint framebuffer);
    GLboolean (APIENTRYP glIsProgram_) (GLuint program);
    GLboolean (APIENTRYP glIsRenderbuffer_) (GLuint renderbuffer);
    GLboolean (APIENTRYP glIsShader_) (GLuint shader);
    GLboolean (APIENTRYP glIsTexture_) (GLuint texture);
    void (APIENTRYP glLineWidth_) (GLfloat width);
    void (APIENTRYP glLinkProgram_) (GLuint program);
    void (APIENTRYP glPixelStorei_) (GLenum pname, GLint param);
    void (APIENTRYP glPolygonOffset_) (GLfloat factor, GLfloat units);
    void (APIENTRYP glReadPixels_) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
    void (APIENTRYP glReleaseShaderCompiler_) (void);
    void (APIENTRYP glRenderbufferStorage_) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    void (APIENTRYP glSampleCoverage_) (GLfloat value, GLboolean invert);
    void (APIENTRYP glScissor_) (GLint x, GLint y, GLsizei width, GLsizei height);
    void (APIENTRYP glShaderBinary_) (GLsizei count, const  GLuint  * shaders, GLenum binaryformat, const void * binary, GLsizei length);
    void (APIENTRYP glShaderSource_) (GLuint shader, GLsizei count, const  GLchar  *const* string, const  GLint  * length);
    void (APIENTRYP glStencilFunc_) (GLenum func, GLint ref, GLuint mask);
    void (APIENTRYP glStencilFuncSeparate_) (GLenum face, GLenum func, GLint ref, GLuint mask);
    void (APIENTRYP glStencilMask_) (GLuint mask);
    void (APIENTRYP glStencilMaskSeparate_) (GLenum face, GLuint mask);
    void (APIENTRYP glStencilOp_) (GLenum fail, GLenum zfail, GLenum zpass);
    void (APIENTRYP glStencilOpSeparate_) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    void (APIENTRYP glTexImage2D_) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glTexParameterf_) (GLenum target, GLenum pname, GLfloat param);
    void (APIENTRYP glTexParameterfv_) (GLenum target, GLenum pname, const  GLfloat  * params);
    void (APIENTRYP glTexParameteri_) (GLenum target, GLenum pname, GLint param);
    void (APIENTRYP glTexParameteriv_) (GLenum target, GLenum pname, const  GLint  * params);
    void (APIENTRYP glTexSubImage2D_) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
    void (APIENTRYP glUniform1f_) (GLint location, GLfloat v0);
    void (APIENTRYP glUniform1fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform1i_) (GLint location, GLint v0);
    void (APIENTRYP glUniform1iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniform2f_) (GLint location, GLfloat v0, GLfloat v1);
    void (APIENTRYP glUniform2fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform2i_) (GLint location, GLint v0, GLint v1);
    void (APIENTRYP glUniform2iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniform3f_) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    void (APIENTRYP glUniform3fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform3i_) (GLint location, GLint v0, GLint v1, GLint v2);
    void (APIENTRYP glUniform3iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniform4f_) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    void (APIENTRYP glUniform4fv_) (GLint location, GLsizei count, const  GLfloat  * value);
    void (APIENTRYP glUniform4i_) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    void (APIENTRYP glUniform4iv_) (GLint location, GLsizei count, const  GLint  * value);
    void (APIENTRYP glUniformMatrix2fv_) (GLint location, GLsizei count, GLboolean transpose, const  GLfloat  * value);
    void (APIENTRYP glUniformMatrix3fv_) (GLint location, GLsizei count, GLboolean transpose, const  GLfloat  * value);
    void (APIENTRYP glUniformMatrix4fv_) (GLint location, GLsizei count, GLboolean transpose, const  GLfloat  * value);
    void (APIENTRYP glUseProgram_) (GLuint program);
    void (APIENTRYP glValidateProgram_) (GLuint program);
    void (APIENTRYP glVertexAttrib1f_) (GLuint index, GLfloat x);
    void (APIENTRYP glVertexAttrib1fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttrib2f_) (GLuint index, GLfloat x, GLfloat y);
    void (APIENTRYP glVertexAttrib2fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttrib3f_) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    void (APIENTRYP glVertexAttrib3fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttrib4f_) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void (APIENTRYP glVertexAttrib4fv_) (GLuint index, const  GLfloat  * v);
    void (APIENTRYP glVertexAttribPointer_) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
    void (APIENTRYP glViewport_) (GLint x, GLint y, GLsizei width, GLsizei height);
  } fps;
} LoadGLapis;

LOADGL_API LoadGLapis oglApis;

/* macros to call OpenGL functions */
#define glActiveTexture         oglApis.fps.glActiveTexture_
#define glAttachShader          oglApis.fps.glAttachShader_
#define glBindAttribLocation    oglApis.fps.glBindAttribLocation_
#define glBindBuffer            oglApis.fps.glBindBuffer_
#define glBindFramebuffer       oglApis.fps.glBindFramebuffer_
#define glBindRenderbuffer      oglApis.fps.glBindRenderbuffer_
#define glBindTexture           oglApis.fps.glBindTexture_
#define glBlendColor            oglApis.fps.glBlendColor_
#define glBlendEquation         oglApis.fps.glBlendEquation_
#define glBlendEquationSeparate oglApis.fps.glBlendEquationSeparate_
#define glBlendFunc             oglApis.fps.glBlendFunc_
#define glBlendFuncSeparate     oglApis.fps.glBlendFuncSeparate_
#define glBufferData            oglApis.fps.glBufferData_
#define glBufferSubData         oglApis.fps.glBufferSubData_
#define glCheckFramebufferStatus oglApis.fps.glCheckFramebufferStatus_
#define glClear                 oglApis.fps.glClear_
#define glClearColor            oglApis.fps.glClearColor_
#define glClearDepthf           oglApis.fps.glClearDepthf_
#define glClearStencil          oglApis.fps.glClearStencil_
#define glColorMask             oglApis.fps.glColorMask_
#define glCompileShader         oglApis.fps.glCompileShader_
#define glCompressedTexImage2D  oglApis.fps.glCompressedTexImage2D_
#define glCompressedTexSubImage2D oglApis.fps.glCompressedTexSubImage2D_
#define glCopyTexImage2D        oglApis.fps.glCopyTexImage2D_
#define glCopyTexSubImage2D     oglApis.fps.glCopyTexSubImage2D_
#define glCreateProgram         oglApis.fps.glCreateProgram_
#define glCreateShader          oglApis.fps.glCreateShader_
#define glCullFace              oglApis.fps.glCullFace_
#define glDeleteBuffers         oglApis.fps.glDeleteBuffers_
#define glDeleteFramebuffers    oglApis.fps.glDeleteFramebuffers_
#define glDeleteProgram         oglApis.fps.glDeleteProgram_
#define glDeleteRenderbuffers   oglApis.fps.glDeleteRenderbuffers_
#define glDeleteShader          oglApis.fps.glDeleteShader_
#define glDeleteTextures        oglApis.fps.glDeleteTextures_
#define glDepthFunc             oglApis.fps.glDepthFunc_
#define glDepthMask             oglApis.fps.glDepthMask_
#define glDepthRangef           oglApis.fps.glDepthRangef_
#define glDetachShader          oglApis.fps.glDetachShader_
#define glDisable               oglApis.fps.glDisable_
#define glDisableVertexAttribArray oglApis.fps.glDisableVertexAttribArray_
#define glDrawArrays            oglApis.fps.glDrawArrays_
#define glDrawElements          oglApis.fps.glDrawElements_
#define glEnable                oglApis.fps.glEnable_
#define glEnableVertexAttribArray oglApis.fps.glEnableVertexAttribArray_
#define glFinish                oglApis.fps.glFinish_
#define glFlush                 oglApis.fps.glFlush_
#define glFramebufferRenderbuffer oglApis.fps.glFramebufferRenderbuffer_
#define glFramebufferTexture2D  oglApis.fps.glFramebufferTexture2D_
#define glFrontFace             oglApis.fps.glFrontFace_
#define glGenBuffers            oglApis.fps.glGenBuffers_
#define glGenerateMipmap        oglApis.fps.glGenerateMipmap_
#define glGenFramebuffers       oglApis.fps.glGenFramebuffers_
#define glGenRenderbuffers      oglApis.fps.glGenRenderbuffers_
#define glGenTextures           oglApis.fps.glGenTextures_
#define glGetActiveAttrib       oglApis.fps.glGetActiveAttrib_
#define glGetActiveUniform      oglApis.fps.glGetActiveUniform_
#define glGetAttachedShaders    oglApis.fps.glGetAttachedShaders_
#define glGetAttribLocation     oglApis.fps.glGetAttribLocation_
#define glGetBooleanv           oglApis.fps.glGetBooleanv_
#define glGetBufferParameteriv  oglApis.fps.glGetBufferParameteriv_
#define glGetError              oglApis.fps.glGetError_
#define glGetFloatv             oglApis.fps.glGetFloatv_
#define glGetFramebufferAttachmentParameteriv oglApis.fps.glGetFramebufferAttachmentParameteriv_
#define glGetIntegerv           oglApis.fps.glGetIntegerv_
#define glGetProgramiv          oglApis.fps.glGetProgramiv_
#define glGetProgramInfoLog     oglApis.fps.glGetProgramInfoLog_
#define glGetRenderbufferParameteriv oglApis.fps.glGetRenderbufferParameteriv_
#define glGetShaderiv           oglApis.fps.glGetShaderiv_
#define glGetShaderInfoLog      oglApis.fps.glGetShaderInfoLog_
#define glGetShaderPrecisionFormat oglApis.fps.glGetShaderPrecisionFormat_
#define glGetShaderSource       oglApis.fps.glGetShaderSource_
#define glGetString             oglApis.fps.glGetString_
#define glGetTexParameterfv     oglApis.fps.glGetTexParameterfv_
#define glGetTexParameteriv     oglApis.fps.glGetTexParameteriv_
#define glGetUniformfv          oglApis.fps.glGetUniformfv_
#define glGetUniformiv          oglApis.fps.glGetUniformiv_
#define glGetUniformLocation    oglApis.fps.glGetUniformLocation_
#define glGetVertexAttribfv     oglApis.fps.glGetVertexAttribfv_
#define glGetVertexAttribiv     oglApis.fps.glGetVertexAttribiv_
#define glGetVertexAttribPointerv oglApis.fps.glGetVertexAttribPointerv_
#define glHint                  oglApis.fps.glHint_
#define glIsBuffer              oglApis.fps.glIsBuffer_
#define glIsEnabled             oglApis.fps.glIsEnabled_
#define glIsFramebuffer         oglApis.fps.glIsFramebuffer_
#define glIsProgram             oglApis.fps.glIsProgram_
#define glIsRenderbuffer        oglApis.fps.glIsRenderbuffer_
#define glIsShader              oglApis.fps.glIsShader_
#define glIsTexture             oglApis.fps.glIsTexture_
#define glLineWidth             oglApis.fps.glLineWidth_
#define glLinkProgram           oglApis.fps.glLinkProgram_
#define glPixelStorei           oglApis.fps.glPixelStorei_
#define glPolygonOffset         oglApis.fps.glPolygonOffset_
#define glReadPixels            oglApis.fps.glReadPixels_
#define glReleaseShaderCompiler oglApis.fps.glReleaseShaderCompiler_
#define glRenderbufferStorage   oglApis.fps.glRenderbufferStorage_
#define glSampleCoverage        oglApis.fps.glSampleCoverage_
#define glScissor               oglApis.fps.glScissor_
#define glShaderBinary          oglApis.fps.glShaderBinary_
#define glShaderSource          oglApis.fps.glShaderSource_
#define glStencilFunc           oglApis.fps.glStencilFunc_
#define glStencilFuncSeparate   oglApis.fps.glStencilFuncSeparate_
#define glStencilMask           oglApis.fps.glStencilMask_
#define glStencilMaskSeparate   oglApis.fps.glStencilMaskSeparate_
#define glStencilOp             oglApis.fps.glStencilOp_
#define glStencilOpSeparate     oglApis.fps.glStencilOpSeparate_
#define glTexImage2D            oglApis.fps.glTexImage2D_
#define glTexParameterf         oglApis.fps.glTexParameterf_
#define glTexParameterfv        oglApis.fps.glTexParameterfv_
#define glTexParameteri         oglApis.fps.glTexParameteri_
#define glTexParameteriv        oglApis.fps.glTexParameteriv_
#define glTexSubImage2D         oglApis.fps.glTexSubImage2D_
#define glUniform1f             oglApis.fps.glUniform1f_
#define glUniform1fv            oglApis.fps.glUniform1fv_
#define glUniform1i             oglApis.fps.glUniform1i_
#define glUniform1iv            oglApis.fps.glUniform1iv_
#define glUniform2f             oglApis.fps.glUniform2f_
#define glUniform2fv            oglApis.fps.glUniform2fv_
#define glUniform2i             oglApis.fps.glUniform2i_
#define glUniform2iv            oglApis.fps.glUniform2iv_
#define glUniform3f             oglApis.fps.glUniform3f_
#define glUniform3fv            oglApis.fps.glUniform3fv_
#define glUniform3i             oglApis.fps.glUniform3i_
#define glUniform3iv            oglApis.fps.glUniform3iv_
#define glUniform4f             oglApis.fps.glUniform4f_
#define glUniform4fv            oglApis.fps.glUniform4fv_
#define glUniform4i             oglApis.fps.glUniform4i_
#define glUniform4iv            oglApis.fps.glUniform4iv_
#define glUniformMatrix2fv      oglApis.fps.glUniformMatrix2fv_
#define glUniformMatrix3fv      oglApis.fps.glUniformMatrix3fv_
#define glUniformMatrix4fv      oglApis.fps.glUniformMatrix4fv_
#define glUseProgram            oglApis.fps.glUseProgram_
#define glValidateProgram       oglApis.fps.glValidateProgram_
#define glVertexAttrib1f        oglApis.fps.glVertexAttrib1f_
#define glVertexAttrib1fv       oglApis.fps.glVertexAttrib1fv_
#define glVertexAttrib2f        oglApis.fps.glVertexAttrib2f_
#define glVertexAttrib2fv       oglApis.fps.glVertexAttrib2fv_
#define glVertexAttrib3f        oglApis.fps.glVertexAttrib3f_
#define glVertexAttrib3fv       oglApis.fps.glVertexAttrib3fv_
#define glVertexAttrib4f        oglApis.fps.glVertexAttrib4f_
#define glVertexAttrib4fv       oglApis.fps.glVertexAttrib4fv_
#define glVertexAttribPointer   oglApis.fps.glVertexAttribPointer_
#define glViewport              oglApis.fps.glViewport_

GL_NS_END

#endif /* LOADGL_GL_ES_VERSION_2_0_GENERATED_H */


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
    "glActiveTexture",
    "glAttachShader",
    "glBindAttribLocation",
    "glBindBuffer",
    "glBindFramebuffer",
    "glBindRenderbuffer",
    "glBindTexture",
    "glBlendColor",
    "glBlendEquation",
    "glBlendEquationSeparate",
    "glBlendFunc",
    "glBlendFuncSeparate",
    "glBufferData",
    "glBufferSubData",
    "glCheckFramebufferStatus",
    "glClear",
    "glClearColor",
    "glClearDepthf",
    "glClearStencil",
    "glColorMask",
    "glCompileShader",
    "glCompressedTexImage2D",
    "glCompressedTexSubImage2D",
    "glCopyTexImage2D",
    "glCopyTexSubImage2D",
    "glCreateProgram",
    "glCreateShader",
    "glCullFace",
    "glDeleteBuffers",
    "glDeleteFramebuffers",
    "glDeleteProgram",
    "glDeleteRenderbuffers",
    "glDeleteShader",
    "glDeleteTextures",
    "glDepthFunc",
    "glDepthMask",
    "glDepthRangef",
    "glDetachShader",
    "glDisable",
    "glDisableVertexAttribArray",
    "glDrawArrays",
    "glDrawElements",
    "glEnable",
    "glEnableVertexAttribArray",
    "glFinish",
    "glFlush",
    "glFramebufferRenderbuffer",
    "glFramebufferTexture2D",
    "glFrontFace",
    "glGenBuffers",
    "glGenerateMipmap",
    "glGenFramebuffers",
    "glGenRenderbuffers",
    "glGenTextures",
    "glGetActiveAttrib",
    "glGetActiveUniform",
    "glGetAttachedShaders",
    "glGetAttribLocation",
    "glGetBooleanv",
    "glGetBufferParameteriv",
    "glGetError",
    "glGetFloatv",
    "glGetFramebufferAttachmentParameteriv",
    "glGetIntegerv",
    "glGetProgramiv",
    "glGetProgramInfoLog",
    "glGetRenderbufferParameteriv",
    "glGetShaderiv",
    "glGetShaderInfoLog",
    "glGetShaderPrecisionFormat",
    "glGetShaderSource",
    "glGetString",
    "glGetTexParameterfv",
    "glGetTexParameteriv",
    "glGetUniformfv",
    "glGetUniformiv",
    "glGetUniformLocation",
    "glGetVertexAttribfv",
    "glGetVertexAttribiv",
    "glGetVertexAttribPointerv",
    "glHint",
    "glIsBuffer",
    "glIsEnabled",
    "glIsFramebuffer",
    "glIsProgram",
    "glIsRenderbuffer",
    "glIsShader",
    "glIsTexture",
    "glLineWidth",
    "glLinkProgram",
    "glPixelStorei",
    "glPolygonOffset",
    "glReadPixels",
    "glReleaseShaderCompiler",
    "glRenderbufferStorage",
    "glSampleCoverage",
    "glScissor",
    "glShaderBinary",
    "glShaderSource",
    "glStencilFunc",
    "glStencilFuncSeparate",
    "glStencilMask",
    "glStencilMaskSeparate",
    "glStencilOp",
    "glStencilOpSeparate",
    "glTexImage2D",
    "glTexParameterf",
    "glTexParameterfv",
    "glTexParameteri",
    "glTexParameteriv",
    "glTexSubImage2D",
    "glUniform1f",
    "glUniform1fv",
    "glUniform1i",
    "glUniform1iv",
    "glUniform2f",
    "glUniform2fv",
    "glUniform2i",
    "glUniform2iv",
    "glUniform3f",
    "glUniform3fv",
    "glUniform3i",
    "glUniform3iv",
    "glUniform4f",
    "glUniform4fv",
    "glUniform4i",
    "glUniform4iv",
    "glUniformMatrix2fv",
    "glUniformMatrix3fv",
    "glUniformMatrix4fv",
    "glUseProgram",
    "glValidateProgram",
    "glVertexAttrib1f",
    "glVertexAttrib1fv",
    "glVertexAttrib2f",
    "glVertexAttrib2fv",
    "glVertexAttrib3f",
    "glVertexAttrib3fv",
    "glVertexAttrib4f",
    "glVertexAttrib4fv",
    "glVertexAttribPointer",
    "glViewport",
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
