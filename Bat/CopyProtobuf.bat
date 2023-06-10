@echo on

xcopy "%ProtobufInclude%/*.h" "../protobuf/src" /F /Y /E  
xcopy "%ProtobufInclude%/*.inc" "../protobuf/src" /F /Y /E  

xcopy "%ProtobufWin32DebugLib%/*.lib" "../protobuf/BuildWin32/Debug/" /F /Y   
xcopy "%ProtobufWin32DebugLib%/*.dll" "../protobuf/BuildWin32/Debug/" /F /Y  
xcopy "%ProtobufWin32ReleaseLib%/*.lib" "../protobuf/BuildWin32/Release/" /F /Y  
xcopy "%ProtobufWin32ReleaseLib%/*.dll" "../protobuf/BuildWin32/Release/" /F /Y  
xcopy "%ProtobufX64DebugLib%/*.lib" "../protobuf/BuildX64/Debug/" /F /Y   
xcopy "%ProtobufX64DebugLib%/*.dll" "../protobuf/BuildX64/Debug/" /F /Y   
xcopy "%ProtobufX64ReleaseLib%/*.lib" "../protobuf/BuildX64/Release/" /F /Y  
xcopy "%ProtobufX64ReleaseLib%/*.dll" "../protobuf/BuildX64/Release/" /F /Y   

pause