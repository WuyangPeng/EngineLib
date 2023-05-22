@echo on

xcopy "%MongocxxInclude%/*.hpp" "../mongo-cxx-driver/src/mongocxx/" /F /Y /E  

xcopy "%MongoCxxDriverWin32DebugLib%/*.lib" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Debug/" /F /Y   
xcopy "%MongoCxxDriverWin32DebugLib%/*.dll" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Debug/" /F /Y  
xcopy "%MongoCxxDriverWin32ReleaseLib%/*.lib" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Release/" /F /Y  
xcopy "%MongoCxxDriverWin32ReleaseLib%/*.dll" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Release/" /F /Y  
xcopy "%MongoCxxDriverX64DebugLib%/*.lib" "../mongo-cxx-driver/BuildX64/src/mongocxx/Debug/" /F /Y   
xcopy "%MongoCxxDriverX64DebugLib%/*.dll" "../mongo-cxx-driver/BuildX64/src/mongocxx/Debug/" /F /Y   
xcopy "%MongoCxxDriverX64ReleaseLib%/*.lib" "../mongo-cxx-driver/BuildX64/src/mongocxx/Release/" /F /Y  
xcopy "%MongoCxxDriverX64ReleaseLib%/*.dll" "../mongo-cxx-driver/BuildX64/src/mongocxx/Release/" /F /Y   

pause