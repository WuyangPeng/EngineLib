@echo on

echo BoostLib = %BoostLib%
echo  %cd%
setx  BoostLib "%cd%\..\boost\stage\lib"

echo ACEWin32Lib = %ACEWin32Lib%
echo  %cd%
setx  ACEWin32Lib "%cd%\..\ACE\ACE_wrappers\lib\Win32"

echo ACEX64Lib = %ACEX64Lib%
echo  %cd%
setx  ACEX64Lib "%cd%\..\ACE\ACE_wrappers\lib\X64"

echo OpenSSLWin32Lib = %OpenSSLWin32Lib%
echo  %cd%
setx  OpenSSLWin32Lib "%cd%\..\openssl\Win32\release\lib"

echo OpenSSLX64Lib = %OpenSSLX64Lib%
echo  %cd%
setx  OpenSSLX64Lib "%cd%\..\openssl\X64\release\lib"

echo MysqlWin32DebugLib = %MysqlWin32DebugLib%
echo  %cd%
setx  MysqlWin32DebugLib "%cd%\..\mysql\BuildWin32\archive_output_directory\Debug"

echo MysqlWin32ReleaseLib = %MysqlWin32ReleaseLib%
echo  %cd%
setx  MysqlWin32ReleaseLib "%cd%\..\mysql\BuildWin32\archive_output_directory\Release"

echo MysqlX64DebugLib = %MysqlX64DebugLib%
echo  %cd%
setx  MysqlX64DebugLib "%cd%\..\mysql\BuildX64\archive_output_directory\Debug"

echo MysqlX64ReleaseLib = %MysqlX64ReleaseLib%
echo  %cd%
setx  MysqlX64ReleaseLib "%cd%\..\mysql\BuildX64\archive_output_directory\Release"

echo MysqlConnectorWin32DebugLib = %MysqlConnectorWin32DebugLib%
echo  %cd%
setx  MysqlConnectorWin32DebugLib "%cd%\..\mysql-connector-c++\BuildWin32\Debug"

echo MysqlConnectorWin32ReleaseLib = %MysqlConnectorWin32ReleaseLib%
echo  %cd%
setx  MysqlConnectorWin32ReleaseLib "%cd%\..\mysql-connector-c++\BuildWin32\Release"

echo MysqlConnectorX64DebugLib = %MysqlConnectorX64DebugLib%
echo  %cd%
setx  MysqlConnectorX64DebugLib "%cd%\..\mysql-connector-c++\BuildX64\Debug"

echo MysqlConnectorX64ReleaseLib = %MysqlConnectorX64ReleaseLib%
echo  %cd%
setx  MysqlConnectorX64ReleaseLib "%cd%\..\mysql-connector-c++\BuildX64\Release"

echo FreeglutWin32DebugLib = %FreeglutWin32DebugLib%
echo  %cd%
setx  FreeglutWin32DebugLib "%cd%\..\FreeGLUT\BuildWin32\lib\Debug"

echo FreeglutWin32ReleaseLib = %FreeglutWin32ReleaseLib%
echo  %cd%
setx  FreeglutWin32ReleaseLib "%cd%\..\FreeGLUT\BuildWin32\lib\Release"

echo FreeglutX64DebugLib = %FreeglutX64DebugLib%
echo  %cd%
setx  FreeglutX64DebugLib "%cd%\..\FreeGLUT\BuildX64\lib\Debug"

echo FreeglutX64ReleaseLib = %FreeglutX64ReleaseLib%
echo  %cd%
setx  FreeglutX64ReleaseLib "%cd%\..\FreeGLUT\BuildX64\lib\Release"

echo FreeglutWin32DebugBin = %FreeglutWin32DebugBin%
echo  %cd%
setx  FreeglutWin32DebugBin "%cd%\..\FreeGLUT\BuildWin32\bin\Debug"

echo FreeglutWin32ReleaseBin = %FreeglutWin32ReleaseBin%
echo  %cd%
setx  FreeglutWin32ReleaseBin "%cd%\..\FreeGLUT\BuildWin32\bin\Release"

echo FreeglutX64DebugBin = %FreeglutX64DebugBin%
echo  %cd%
setx  FreeglutX64DebugBin "%cd%\..\FreeGLUT\BuildX64\bin\Debug"

echo FreeglutX64ReleaseBin = %FreeglutX64ReleaseBin%
echo  %cd%
setx  FreeglutX64ReleaseBin "%cd%\..\FreeGLUT\BuildX64\bin\Release"

echo VisualLeakDetectorWin32Lib = %VisualLeakDetectorWin32Lib%
echo  %cd%
setx  VisualLeakDetectorWin32Lib "%cd%\..\vld\src\bin\Win32\Release-v143"

echo VisualLeakDetectorX64Lib = %VisualLeakDetectorX64Lib%
echo  %cd%
setx  VisualLeakDetectorX64Lib "%cd%\..\vld\src\bin\x64\Release-v143"

echo OpenALSoftWin32DebugLib = %OpenALSoftWin32DebugLib%
echo  %cd%
setx  OpenALSoftWin32DebugLib "%cd%\..\openal-soft\BuildWin32\Debug"

echo OpenALSoftWin32ReleaseLib = %OpenALSoftWin32ReleaseLib%
echo  %cd%
setx  OpenALSoftWin32ReleaseLib "%cd%\..\openal-soft\BuildWin32\Release"

echo OpenALSoftX64DebugLib = %OpenALSoftX64DebugLib%
echo  %cd%
setx  OpenALSoftX64DebugLib "%cd%\..\openal-soft\Buildx64\Debug"

echo OpenALSoftX64ReleaseLib = %OpenALSoftX64ReleaseLib%
echo  %cd%
setx  OpenALSoftX64ReleaseLib "%cd%\..\openal-soft\Buildx64\Release"

echo ZlibWin32DebugLib = %ZlibWin32DebugLib%
echo  %cd%
setx  ZlibWin32DebugLib "%cd%\..\zlib\BuildWin32\Debug" 

echo ZlibWin32ReleaseLib = %ZlibWin32ReleaseLib%
echo  %cd%
setx  ZlibWin32ReleaseLib "%cd%\..\zlib\BuildWin32\Release" 

echo ZlibX64DebugLib = %ZlibX64DebugLib%
echo  %cd%
setx  ZlibX64DebugLib "%cd%\..\zlib\BuildX64\Debug" 

echo ZlibX64ReleaseLib = %ZlibX64ReleaseLib%
echo  %cd%
setx  ZlibX64ReleaseLib "%cd%\..\zlib\BuildX64\Release" 

echo FreetypeWin32DebugLib = %FreetypeWin32DebugLib%
echo  %cd%
setx  FreetypeWin32DebugLib "%cd%\..\freetype\BuildWin32\Debug" 

echo FreetypeWin32ReleaseLib = %FreetypeWin32ReleaseLib%
echo  %cd%
setx  FreetypeWin32ReleaseLib "%cd%\..\freetype\BuildWin32\Release" 

echo FreetypeX64DebugLib = %FreetypeX64DebugLib%
echo  %cd%
setx  FreetypeX64DebugLib "%cd%\..\freetype\BuildX64\Debug" 

echo FreetypeX64ReleaseLib = %FreetypeX64ReleaseLib%
echo  %cd%
setx  FreetypeX64ReleaseLib "%cd%\..\freetype\BuildX64\Release" 

echo LuaWin32DebugLib = %LuaWin32DebugLib%
echo  %cd%
setx  LuaWin32DebugLib "%cd%\..\lua\build\lua\Win32\Debug"

echo LuaWin32ReleaseLib = %LuaWin32ReleaseLib%
echo  %cd%
setx  LuaWin32ReleaseLib "%cd%\..\lua\build\lua\Win32\Release"

echo LuaX64DebugLib = %LuaX64DebugLib%
echo  %cd%
setx  LuaX64DebugLib "%cd%\..\lua\build\lua\x64\Debug"

echo LuaX64ReleaseLib = %LuaX64ReleaseLib%
echo  %cd%
setx  LuaX64ReleaseLib "%cd%\..\lua\build\lua\x64\Release"

echo OpenXLSXWin32DebugLib = %OpenXLSXWin32DebugLib%
echo  %cd%
setx  OpenXLSXWin32DebugLib "%cd%\..\OpenXLSX\BuildWin32\output\Debug"

echo OpenXLSXWin32ReleaseLib = %OpenXLSXWin32ReleaseLib%
echo  %cd%
setx  OpenXLSXWin32ReleaseLib "%cd%\..\OpenXLSX\BuildWin32\output\Release"

echo OpenXLSXX64DebugLib = %OpenXLSXX64DebugLib%
echo  %cd%
setx  OpenXLSXX64DebugLib "%cd%\..\OpenXLSX\BuildX64\output\Debug"

echo OpenXLSXX64ReleaseLib = %OpenXLSXX64ReleaseLib%
echo  %cd%
setx  OpenXLSXX64ReleaseLib "%cd%\..\OpenXLSX\BuildX64\output\Release"

echo MinizWin32DebugLib = %MinizWin32DebugLib%
echo  %cd%
setx  MinizWin32DebugLib "%cd%\..\miniz\miniz\Win32\Debug"

echo MinizWin32ReleaseLib = %MinizWin32ReleaseLib%
echo  %cd%
setx  MinizWin32ReleaseLib "%cd%\..\miniz\miniz\Win32\Release"

echo MinizX64DebugLib = %MinizX64DebugLib%
echo  %cd%
setx  MinizX64DebugLib "%cd%\..\miniz\miniz\x64\Debug"

echo MinizX64ReleaseLib = %MinizX64ReleaseLib%
echo  %cd%
setx  MinizX64ReleaseLib "%cd%\..\miniz\miniz\x64\Release"

echo ProtobufWin32DebugLib = %ProtobufWin32DebugLib%
echo  %cd%
setx  ProtobufWin32DebugLib "%cd%\..\protobuf\BuildWin32\Debug"

echo ProtobufWin32ReleaseLib = %ProtobufWin32ReleaseLib%
echo  %cd%
setx  ProtobufWin32ReleaseLib "%cd%\..\protobuf\BuildWin32\Release"

echo ProtobufX64DebugLib = %ProtobufX64DebugLib%
echo  %cd%
setx  ProtobufX64DebugLib "%cd%\..\protobuf\BuildX64\Debug"

echo ProtobufX64ReleaseLib = %ProtobufX64ReleaseLib%
echo  %cd%
setx  ProtobufX64ReleaseLib "%cd%\..\protobuf\BuildX64\Release"

echo ActiveMQWin32DebugLib = %ActiveMQWin32DebugLib%
echo  %cd%
setx  ActiveMQWin32DebugLib "%cd%\..\activemq\vs2010-build\Win32\DebugDLL"

echo ActiveMQWin32ReleaseLib = %ActiveMQWin32ReleaseLib%
echo  %cd%
setx  ActiveMQWin32ReleaseLib "%cd%\..\activemq\vs2010-build\Win32\ReleaseDLL"

echo ActiveMQX64DebugLib = %ActiveMQX64DebugLib%
echo  %cd%
setx  ActiveMQX64DebugLib "%cd%\..\activemq\vs2010-build\x64\DebugDLL"

echo ActiveMQX64ReleaseLib = %ActiveMQX64ReleaseLib%
echo  %cd%
setx  ActiveMQX64ReleaseLib "%cd%\..\activemq\vs2010-build\x64\ReleaseDLL"

echo AprWin32DebugLib = %AprWin32DebugLib%
echo  %cd%
setx  AprWin32DebugLib "%cd%\..\apr\BuildWin32\Debug"

echo AprWin32ReleaseLib = %AprWin32ReleaseLib%
echo  %cd%
setx  AprWin32ReleaseLib "%cd%\..\apr\BuildWin32\Release"

echo AprX64DebugLib = %AprX64DebugLib%
echo  %cd%
setx  AprX64DebugLib "%cd%\..\apr\BuildX64\Debug"

echo AprX64ReleaseLib = %AprX64ReleaseLib%
echo  %cd%
setx  AprX64ReleaseLib "%cd%\..\apr\BuildX64\Release"

echo MongoCxxDriverWin32DebugLib = %MongoCxxDriverWin32DebugLib%
echo  %cd%
setx  MongoCxxDriverWin32DebugLib "%cd%\..\mongo-cxx-driver\BuildWin32\src\mongocxx\Debug"

echo MongoCxxDriverWin32ReleaseLib = %MongoCxxDriverWin32ReleaseLib%
echo  %cd%
setx  MongoCxxDriverWin32ReleaseLib "%cd%\..\mongo-cxx-driver\BuildWin32\src\mongocxx\Release"

echo MongoCxxDriverX64DebugLib = %MongoCxxDriverX64DebugLib%
echo  %cd%
setx  MongoCxxDriverX64DebugLib "%cd%\..\mongo-cxx-driver\BuildX64\src\mongocxx\Debug"

echo MongoCxxDriverX64ReleaseLib = %MongoCxxDriverX64ReleaseLib%
echo  %cd%
setx  MongoCxxDriverX64ReleaseLib "%cd%\..\mongo-cxx-driver\BuildX64\src\mongocxx\Release"

echo BsoncxxWin32DebugLib = %BsoncxxWin32DebugLib%
echo  %cd%
setx  BsoncxxWin32DebugLib "%cd%\..\mongo-cxx-driver\BuildWin32\src\bsoncxx\Debug"

echo BsoncxxWin32ReleaseLib = %BsoncxxWin32ReleaseLib%
echo  %cd%
setx  BsoncxxWin32ReleaseLib "%cd%\..\mongo-cxx-driver\BuildWin32\src\bsoncxx\Release"

echo BsoncxxX64DebugLib = %BsoncxxX64DebugLib%
echo  %cd%
setx  BsoncxxX64DebugLib "%cd%\..\mongo-cxx-driver\BuildX64\src\bsoncxx\Debug"

echo BsoncxxX64ReleaseLib = %BsoncxxX64ReleaseLib%
echo  %cd%
setx  BsoncxxX64ReleaseLib "%cd%\..\mongo-cxx-driver\BuildX64\src\bsoncxx\Release"

echo HiredisWin32DebugLib = %HiredisWin32DebugLib%
echo  %cd%
setx  HiredisWin32DebugLib "%cd%\..\hiredis\BuildWin32\Debug"

echo HiredisWin32ReleaseLib = %HiredisWin32ReleaseLib%
echo  %cd%
setx  HiredisWin32ReleaseLib "%cd%\..\hiredis\BuildWin32\Release"

echo HiredisX64DebugLib = %HiredisX64DebugLib%
echo  %cd%
setx  HiredisX64DebugLib "%cd%\..\hiredis\BuildX64\Debug"

echo HiredisX64ReleaseLib = %HiredisX64ReleaseLib%
echo  %cd%
setx  HiredisX64ReleaseLib "%cd%\..\hiredis\BuildX64\Release"

echo LibsEnvironmentWin32Lib = %LibsEnvironmentWin32Lib%
echo %cd%
setx LibsEnvironmentWin32Lib "%BoostLib%;%ACEWin32Lib%;%OpenSSLWin32Lib%;" 

echo LibsEnvironmentWin32DebugLib = %LibsEnvironmentWin32DebugLib%
echo %cd%
setx LibsEnvironmentWin32DebugLib "%MySqlWin32DebugLib%;%MySqlConnectorWin32DebugLib%;%VisualLeakDetectorWin32Lib%;%FreeglutWin32DebugLib%;%OpenALSoftWin32DebugLib%;%ZlibWin32DebugLib%;%FreetypeWin32DebugLib%;%LuaWin32DebugLib%;%OpenXLSXWin32DebugLib%;%MinizWin32DebugLib%;%ProtobufWin32DebugLib%;%ActiveMQWin32DebugLib%;%AprWin32DebugLib%;%MongoCxxDriverWin32DebugLib%;%BsoncxxWin32DebugLib%;%HiredisWin32DebugLib%;" 

echo LibsEnvironmentWin32ReleaseLib = %LibsEnvironmentWin32ReleaseLib%
echo %cd%
setx LibsEnvironmentWin32ReleaseLib "%MySqlWin32ReleaseLib%;%MySqlConnectorWin32ReleaseLib%;%FreeglutWin32ReleaseLib%;%OpenALSoftWin32ReleaseLib%;%ZlibWin32ReleaseLib%;%FreetypeWin32ReleaseLib%;%LuaWin32ReleaseLib%;%OpenXLSXWin32ReleaseLib%;%MinizWin32ReleaseLib%;%ProtobufWin32ReleaseLib%;%ActiveMQWin32ReleaseLib%;%AprWin32ReleaseLib%;%MongoCxxDriverWin32ReleaseLib%;%BsoncxxWin32ReleaseLib%;%HiredisWin32ReleaseLib%;" 

echo LibsEnvironmentX64Lib = %LibsEnvironmentX64Lib%
echo %cd% 
setx LibsEnvironmentX64Lib "%BoostLib%;%ACEX64Lib%;%OpenSSLX64Lib%;" 

echo LibsEnvironmentX64DebugLib = %LibsEnvironmentX64DebugLib%
echo %cd%
setx LibsEnvironmentX64DebugLib "%MySqlX64DebugLib%;%MySqlConnectorX64DebugLib%;%VisualLeakDetectorX64Lib%;%FreeglutX64DebugLib%;%OpenALSoftX64DebugLib%;%ZlibX64DebugLib%;%FreetypeX64DebugLib%;%LuaX64DebugLib%;%OpenXLSXX64DebugLib%;%MinizX64DebugLib%;%ProtobufX64DebugLib%;%ActiveMQX64DebugLib%;%AprX64DebugLib%;%MongoCxxDriverX64DebugLib%;%BsoncxxX64DebugLib%;%HiredisX64DebugLib%;" 

echo LibsEnvironmentX64ReleaseLib = %LibsEnvironmentX64ReleaseLib%
echo %cd%
setx LibsEnvironmentX64ReleaseLib "%MySqlX64ReleaseLib%;%MySqlConnectorX64ReleaseLib%;%FreeglutX64ReleaseLib%;%OpenALSoftX64ReleaseLib%;%ZlibX64ReleaseLib%;%FreetypeX64ReleaseLib%;%LuaX64ReleaseLib%;%OpenXLSXX64ReleaseLib%;%MinizX64ReleaseLib%;%ProtobufX64ReleaseLib%;%ActiveMQX64ReleaseLib%;%AprX64ReleaseLib%;%MongoCxxDriverX64ReleaseLib%;%BsoncxxX64ReleaseLib%;%HiredisX64ReleaseLib%;" 

pause