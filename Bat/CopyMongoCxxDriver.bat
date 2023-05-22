@echo on

xcopy "%MongocxxInclude%\*.hpp" "../mongo-cxx-driver/src/mongocxx/" /F /Y /E   

pause