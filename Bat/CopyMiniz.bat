@echo on

xcopy "%MinizInclude%/miniz.h" "../miniz/" /F /Y  
xcopy "%MinizInclude%/miniz.c" "../miniz/" /F /Y 

xcopy "%MinizInclude%/miniz/Debug/*.lib" "../miniz/miniz/Debug/" /F /Y   
xcopy "%MinizInclude%/miniz/Release/*.lib" "../miniz/miniz/Release/" /F /Y  
xcopy "%MinizInclude%/miniz/x64/Debug/*.lib" "../miniz/miniz/x64/Debug/" /F /Y   
xcopy "%MinizInclude%/miniz/x64/Release/*.lib" "../miniz/miniz/x64/Release/" /F /Y  

pause