@echo on

xcopy "%BoostInclude%/boost/*.h" "../boost/boost/" /F /Y /E 
xcopy "%BoostInclude%/boost/*.hpp" "../boost/boost/" /F /Y /E 
xcopy "%BoostInclude%/boost/*.ipp" "../boost/boost/" /F /Y /E 

xcopy "%BoostLib%/*chrono*" "../boost/stage/lib/" /F /Y  
xcopy "%BoostLib%/*time*" "../boost/stage/lib/" /F /Y 
xcopy "%BoostLib%/*thread*" "../boost/stage/lib/" /F /Y 

pause