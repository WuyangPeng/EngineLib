@echo on

xcopy "%HiredisInclude%/*.h" "../hiredis/" /F /Y /E  

xcopy "%HiredisWin32DebugLib%/*.lib" "../hiredis/BuildWin32/Debug/" /F /Y   
xcopy "%HiredisWin32DebugLib%/*.dll" "../hiredis/BuildWin32/Debug/" /F /Y  
xcopy "%HiredisWin32ReleaseLib%/*.lib" "../hiredis/BuildWin32/Release/" /F /Y  
xcopy "%HiredisWin32ReleaseLib%/*.dll" "../hiredis/BuildWin32/Release/" /F /Y  
xcopy "%HiredisX64DebugLib%/*.lib" "../hiredis/BuildX64/Debug/" /F /Y   
xcopy "%HiredisX64DebugLib%/*.dll" "../hiredis/BuildX64/Debug/" /F /Y   
xcopy "%HiredisX64ReleaseLib%/*.lib" "../hiredis/BuildX64/Release/" /F /Y  
xcopy "%HiredisX64ReleaseLib%/*.dll" "../hiredis/BuildX64/Release/" /F /Y   

pause