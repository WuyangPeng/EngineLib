@echo on

xcopy "%FreetypeInclude%/*.h" "../freetype/include/" /F /Y   
xcopy "%FreetypeInclude%/freetype/*.h" "../freetype/include/freetype" /F /Y   
xcopy "%FreetypeInclude%/freetype/config/*.h" "../freetype/include/freetype/config" /F /Y   
xcopy "%FreetypeInclude%/freetype/internal/*.h" "../freetype/include/freetype/internal" /F /Y   
xcopy "%FreetypeInclude%/freetype/internal/services/*.h" "../freetype/include/freetype/internal/services" /F /Y   

xcopy "%FreetypeWin32DebugLib%/*.*" "../freetype/BuildWin32/Debug" /F /Y   

xcopy "%FreetypeWin32ReleaseLib%/*.*" "../freetype/BuildWin32/Release" /F /Y    

xcopy "%FreetypeX64DebugLib%/*.*" "../freetype/BuildX64/Debug" /F /Y    

xcopy "%FreetypeX64ReleaseLib%/*.*" "../freetype/BuildX64/Release" /F /Y  

pause