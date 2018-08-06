@del *.o *.a *.dll

gcc -c -s -O3 nanovg\src\nanovg.c
ar rcs libnanovg.a *.o
@del *.o
gcc -s -O3 -mdll -o nvg.dll nanovg.def lua-nanovg.c libnanovg.a -lopengl32 -llua53

@pause
