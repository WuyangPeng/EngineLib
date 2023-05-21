@echo on

xcopy "%MysqlConnectorInclude%/mysql/*.h" "../mysql-connector-c++/include/mysql" /F /Y  
xcopy "%MysqlConnectorInclude%/mysqlx/*.h" "../mysql-connector-c++/include/mysqlx" /F /Y  
xcopy "%MysqlConnectorInclude%/mysqlx/devapi/*.h" "../mysql-connector-c++/include/mysqlx/devapi" /F /Y  
xcopy "%MysqlConnectorInclude%/mysqlx/common/*.h" "../mysql-connector-c++/include/mysqlx/common" /F /Y  
xcopy "%MysqlConnectorMqsqlxInclude%/*.h" "../mysql-connector-c++/BuildX64/include/mysqlx" /F /Y

xcopy "%MysqlConnectorWin32DebugLib%/*.lib" "../mysql-connector-c++/BuildWin32/Debug/" /F /Y   
xcopy "%MysqlConnectorWin32DebugLib%/*.dll" "../mysql-connector-c++/BuildWin32/Debug/" /F /Y  
xcopy "%MysqlConnectorWin32ReleaseLib%/*.lib" "../mysql-connector-c++/BuildWin32/Release/" /F /Y  
xcopy "%MysqlConnectorWin32ReleaseLib%/*.dll" "../mysql-connector-c++/BuildWin32/Release/" /F /Y  
xcopy "%MysqlConnectorX64DebugLib%/*.lib" "../mysql-connector-c++/BuildX64/Debug/" /F /Y   
xcopy "%MysqlConnectorX64DebugLib%/*.dll" "../mysql-connector-c++/BuildX64/Debug/" /F /Y   
xcopy "%MysqlConnectorX64ReleaseLib%/*.lib" "../mysql-connector-c++/BuildX64/Release/" /F /Y  
xcopy "%MysqlConnectorX64ReleaseLib%/*.dll" "../mysql-connector-c++/BuildX64/Release/" /F /Y  

pause