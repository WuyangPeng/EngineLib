@echo on

xcopy "%MysqlConnectorInclude%/*.h" "../mysql-connector-c++/include/" /F /Y /E
xcopy "%MysqlConnectorMqsqlxInclude%/*.h" "../mysql-connector-c++/BuildX64/include/mysqlx" /F /Y /E

xcopy "%MysqlConnectorWin32DebugLib%/*.lib" "../mysql-connector-c++/BuildWin32/Debug/" /F /Y   
xcopy "%MysqlConnectorWin32DebugLib%/*.dll" "../mysql-connector-c++/BuildWin32/Debug/" /F /Y  
xcopy "%MysqlConnectorWin32ReleaseLib%/*.lib" "../mysql-connector-c++/BuildWin32/Release/" /F /Y  
xcopy "%MysqlConnectorWin32ReleaseLib%/*.dll" "../mysql-connector-c++/BuildWin32/Release/" /F /Y  
xcopy "%MysqlConnectorX64DebugLib%/*.lib" "../mysql-connector-c++/BuildX64/Debug/" /F /Y   
xcopy "%MysqlConnectorX64DebugLib%/*.dll" "../mysql-connector-c++/BuildX64/Debug/" /F /Y   
xcopy "%MysqlConnectorX64ReleaseLib%/*.lib" "../mysql-connector-c++/BuildX64/Release/" /F /Y  
xcopy "%MysqlConnectorX64ReleaseLib%/*.dll" "../mysql-connector-c++/BuildX64/Release/" /F /Y  

pause