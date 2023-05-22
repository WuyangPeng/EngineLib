@echo on

xcopy "%FreetypeInclude%/*.h" "../freetype/include/" /F /Y /E  

xcopy "%FreetypeWin32DebugLib%/*.*" "../freetype/BuildWin32/Debug" /F /Y   

xcopy "%FreetypeWin32ReleaseLib%/*.*" "../freetype/BuildWin32/Release" /F /Y    

xcopy "%FreetypeX64DebugLib%/*.*" "../freetype/BuildX64/Debug" /F /Y    

xcopy "%FreetypeX64ReleaseLib%/*.*" "../freetype/BuildX64/Release" /F /Y  

pause