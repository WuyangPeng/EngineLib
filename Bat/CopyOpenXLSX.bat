@echo on

xcopy "%OpenXLSXInclude%/*.hpp" "../OpenXLSX/OpenXLSX/" /F /Y /E

xcopy "%OpenXLSXWin32DebugLib%/*.lib" "../OpenXLSX/OpenXLSX/BuildWin32/output/Debug/" /F /Y   
xcopy "%OpenXLSXWin32ReleaseLib%/*.lib" "../OpenXLSX/OpenXLSX/BuildWin32/output/Release/" /F /Y  
xcopy "%OpenXLSXX64DebugLib%/*.lib" "../OpenXLSX/OpenXLSX/BuildX64/output/Debug/" /F /Y   
xcopy "%OpenXLSXX64ReleaseLib%/*.lib" "../OpenXLSX/OpenXLSX/BuildX64/output/Release/" /F /Y  

xcopy "%OpenXLSXWin32DebugLib%/*.dll" "../OpenXLSX/OpenXLSX/BuildWin32/output/Debug/" /F /Y   
xcopy "%OpenXLSXWin32ReleaseLib%/*.dll" "../OpenXLSX/OpenXLSX/BuildWin32/output/Release/" /F /Y  
xcopy "%OpenXLSXX64DebugLib%/*.dll" "../OpenXLSX/OpenXLSX/BuildX64/output/Debug/" /F /Y   
xcopy "%OpenXLSXX64ReleaseLib%/*.dll" "../OpenXLSX/OpenXLSX/BuildX64/output/Release/" /F /Y  

pause