@echo on

xcopy "C:/Program Files (x86)/mongo-c-driver/*" "%MongocxxInclude%/../../BuildWin32/mongo-c-driver" /F /Y /E

pause