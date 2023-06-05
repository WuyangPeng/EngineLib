@echo on

xcopy "%MysqlInclude%/*.h" "../mysql/include/" /F /Y /E 

xcopy "%MysqlWin32DebugLib%/mysqlclient.lib" "../mysql/BuildWin32/archive_output_directory/Debug/" /F /Y   
xcopy "%MysqlWin32ReleaseLib%/mysqlclient.lib" "../mysql/BuildWin32/archive_output_directory/Release/" /F /Y   
xcopy "%MysqlX64DebugLib%/mysqlclient.lib" "../mysql/BuildX64/archive_output_directory/Debug/" /F /Y   
xcopy "%MysqlX64ReleaseLib%/mysqlclient.lib" "../mysql/BuildX64/archive_output_directory/Release/" /F /Y   

pause