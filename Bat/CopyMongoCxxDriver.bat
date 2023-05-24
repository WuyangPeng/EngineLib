@echo on

xcopy "%MongocxxInclude%/*.hpp" "../mongo-cxx-driver/src/" /F /Y /E  

xcopy "%MongoCxxDriverWin32DebugLib%/*.lib" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Debug/" /F /Y   
xcopy "%MongoCxxDriverWin32DebugLib%/*.dll" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Debug/" /F /Y  
xcopy "%MongoCxxDriverWin32ReleaseLib%/*.lib" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Release/" /F /Y  
xcopy "%MongoCxxDriverWin32ReleaseLib%/*.dll" "../mongo-cxx-driver/BuildWin32/src/mongocxx/Release/" /F /Y  
xcopy "%MongoCxxDriverX64DebugLib%/*.lib" "../mongo-cxx-driver/BuildX64/src/mongocxx/Debug/" /F /Y   
xcopy "%MongoCxxDriverX64DebugLib%/*.dll" "../mongo-cxx-driver/BuildX64/src/mongocxx/Debug/" /F /Y   
xcopy "%MongoCxxDriverX64ReleaseLib%/*.lib" "../mongo-cxx-driver/BuildX64/src/mongocxx/Release/" /F /Y  
xcopy "%MongoCxxDriverX64ReleaseLib%/*.dll" "../mongo-cxx-driver/BuildX64/src/mongocxx/Release/" /F /Y   

xcopy "%BsoncxxWin32DebugLib%/*.lib" "../mongo-cxx-driver/BuildWin32/src/bsoncxx/Debug/" /F /Y   
xcopy "%BsoncxxWin32DebugLib%/*.dll" "../mongo-cxx-driver/BuildWin32/src/bsoncxx/Debug/" /F /Y  
xcopy "%BsoncxxWin32ReleaseLib%/*.lib" "../mongo-cxx-driver/BuildWin32/src/bsoncxx/Release/" /F /Y  
xcopy "%BsoncxxWin32ReleaseLib%/*.dll" "../mongo-cxx-driver/BuildWin32/src/bsoncxx/Release/" /F /Y  
xcopy "%BsoncxxX64DebugLib%/*.lib" "../mongo-cxx-driver/BuildX64/src/bsoncxx/Debug/" /F /Y   
xcopy "%BsoncxxX64DebugLib%/*.dll" "../mongo-cxx-driver/BuildX64/src/bsoncxx/Debug/" /F /Y   
xcopy "%BsoncxxX64ReleaseLib%/*.lib" "../mongo-cxx-driver/BuildX64/src/bsoncxx/Release/" /F /Y  
xcopy "%BsoncxxX64ReleaseLib%/*.dll" "../mongo-cxx-driver/BuildX64/src/bsoncxx/Release/" /F /Y  

xcopy "%MongocxxInclude%/../BuildX64/mongo-c-driver/*.dll" "../mongo-cxx-driver/BuildX64/mongo-c-driver/" /F /Y /E 
xcopy "%MongocxxInclude%/../BuildWin32/mongo-c-driver/*.dll" "../mongo-cxx-driver/BuildWin32/mongo-c-driver/" /F /Y /E 

xcopy "%MongocxxInclude%/../BuildX64/src/*.hpp" "../mongo-cxx-driver/BuildX64/src/" /F /Y /E 
xcopy "%MongocxxInclude%/../BuildWin32/src/*.hpp" "../mongo-cxx-driver/BuildWin32/src/" /F /Y /E 


pause