@echo on

xcopy "%ActiveMQInclude%/cms/*.h" "../activemq/src/main/cms" /F /Y /E
xcopy "%ActiveMQInclude%/activemq/*.h" "../activemq/src/main/activemq/" /F /Y /E 
xcopy "%ActiveMQInclude%/decaf/*.h" "../activemq/src/main/decaf/" /F /Y /E 

xcopy "%ActiveMQWin32DebugLib%/*.dll" "../activemq/vs2010-build/Win32/DebugDLL" /F /Y
xcopy "%ActiveMQWin32DebugLib%/*.lib" "../activemq/vs2010-build/Win32/DebugDLL" /F /Y  

xcopy "%ActiveMQWin32ReleaseLib%/*.dll" "../activemq/vs2010-build/Win32/ReleaseDLL" /F /Y
xcopy "%ActiveMQWin32ReleaseLib%/*.lib" "../activemq/vs2010-build/Win32/ReleaseDLL" /F /Y  

xcopy "%ActiveMQX64DebugLib%/*.dll" "../activemq/vs2010-build/x64/DebugDLL" /F /Y
xcopy "%ActiveMQX64DebugLib%/*.lib" "../activemq/vs2010-build/x64/DebugDLL" /F /Y  

xcopy "%ActiveMQX64ReleaseLib%/*.dll" "../activemq/vs2010-build/x64/ReleaseDLL" /F /Y
xcopy "%ActiveMQX64ReleaseLib%/*.lib" "../activemq/vs2010-build/x64/ReleaseDLL" /F /Y  

pause