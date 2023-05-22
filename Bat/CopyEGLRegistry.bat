@echo on

xcopy "%OpengEGLlInclude%/*.h" "../EGL-Registry/api/" /F /Y /E  

pause