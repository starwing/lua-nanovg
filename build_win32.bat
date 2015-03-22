@del *.o *.a *.dll

gcc -c -s -O3 gl_2_0_core.c
gcc -c -s -O3 nanovg\src\nanovg.c
ar rcs libnanovg.a *.o
@del *.o
gcc -s -O3 -mdll -o nvg.dll nanovg.def lua-nanovg.c libnanovg.a -lopengl32 -llua53

@set CFLAGS=-D_GLFW_USE_OPENGL -D_GLFW_WIN32 -D_GLFW_WGL -D_GLFW_BUILD_DLL
gcc -c -s -O3 %CFLAGS%  glfw\src\context.c        
gcc -c -s -O3 %CFLAGS%  glfw\src\init.c           
gcc -c -s -O3 %CFLAGS%  glfw\src\input.c          
gcc -c -s -O3 %CFLAGS%  glfw\src\monitor.c        
gcc -c -s -O3 %CFLAGS%  glfw\src\window.c         
gcc -c -s -O3 %CFLAGS%  glfw\src\wgl_context.c    
gcc -c -s -O3 %CFLAGS%  glfw\src\win32_init.c     
gcc -c -s -O3 %CFLAGS%  glfw\src\win32_monitor.c  
gcc -c -s -O3 %CFLAGS%  glfw\src\win32_time.c     
gcc -c -s -O3 %CFLAGS%  glfw\src\win32_tls.c      
gcc -c -s -O3 %CFLAGS%  glfw\src\win32_window.c   
gcc -c -s -O3 %CFLAGS%  glfw\src\winmm_joystick.c 
ar rcs libglfw3.a *.o
@del *.o
gcc -s -O3 -mdll -o glfw.dll lua-glfw.c libglfw3.a -lgdi32 -lopengl32 -llua53

@pause
