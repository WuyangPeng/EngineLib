@echo on

xcopy "%ActiveMQInclude%/cms/*.h" "../activemq/src/main/cms" /F /Y 
xcopy "%ActiveMQInclude%/activemq/cmsutil/*.h" "../activemq/src/main/activemq/cmsutil" /F /Y 
xcopy "%ActiveMQInclude%/activemq/commands/*.h" "../activemq/src/main/activemq/commands" /F /Y 
xcopy "%ActiveMQInclude%/activemq/core/*.h" "../activemq/src/main/activemq/core" /F /Y 
xcopy "%ActiveMQInclude%/activemq/exceptions/*.h" "../activemq/src/main/activemq/exceptions" /F /Y 
xcopy "%ActiveMQInclude%/activemq/io/*.h" "../activemq/src/main/activemq/io" /F /Y 
xcopy "%ActiveMQInclude%/activemq/library/*.h" "../activemq/src/main/activemq/library" /F /Y 
xcopy "%ActiveMQInclude%/activemq/state/*.h" "../activemq/src/main/activemq/state" /F /Y 
xcopy "%ActiveMQInclude%/activemq/threads/*.h" "../activemq/src/main/activemq/threads" /F /Y 
xcopy "%ActiveMQInclude%/activemq/transport/*.h" "../activemq/src/main/activemq/transport" /F /Y 
xcopy "%ActiveMQInclude%/activemq/util/*.h" "../activemq/src/main/activemq/util" /F /Y 
xcopy "%ActiveMQInclude%/activemq/wireformat/*.h" "../activemq/src/main/activemq/wireformat" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/*.h" "../activemq/src/main/decaf/internal" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/io/*.h" "../activemq/src/main/decaf/internal/io/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/net/*.h" "../activemq/src/main/decaf/internal/net/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/net/file/*.h" "../activemq/src/main/decaf/internal/net/file" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/net/http/*.h" "../activemq/src/main/decaf/internal/net/http" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/net/https/*.h" "../activemq/src/main/decaf/internal/net/https" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/net/ssl/*.h" "../activemq/src/main/decaf/internal/net/ssl" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/net/ssl/openssl/*.h" "../activemq/src/main/decaf/internal/net/ssl/openssl" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/net/tcp/*.h" "../activemq/src/main/decaf/internal/net/tcp" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/nio/*.h" "../activemq/src/main/decaf/internal/nio/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/security/*.h" "../activemq/src/main/decaf/internal/security/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/security/provider/*.h" "../activemq/src/main/decaf/internal/security/provider/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/security/provider/crypto/*.h" "../activemq/src/main/decaf/internal/security/provider/crypto" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/security/unix/*.h" "../activemq/src/main/decaf/internal/security/unix/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/security/windows/*.h" "../activemq/src/main/decaf/internal/security/windows/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/util/*.h" "../activemq/src/main/decaf/internal/util/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/util/concurrent/*.h" "../activemq/src/main/decaf/internal/util/concurrent" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/util/concurrent/unix/*.h" "../activemq/src/main/decaf/internal/util/concurrent/unix" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/util/concurrent/windows/*.h" "../activemq/src/main/decaf/internal/util/concurrent/windows" /F /Y 
xcopy "%ActiveMQInclude%/decaf/internal/util/zip/*.h" "../activemq/src/main/decaf/internal/util/zip" /F /Y 
xcopy "%ActiveMQInclude%/decaf/io/*.h" "../activemq/src/main/decaf/io" /F /Y 
xcopy "%ActiveMQInclude%/decaf/lang/*.h" "../activemq/src/main/decaf/lang" /F /Y 
xcopy "%ActiveMQInclude%/decaf/lang/exceptions/*.h" "../activemq/src/main/decaf/lang/exceptions" /F /Y 
xcopy "%ActiveMQInclude%/decaf/net/*.h" "../activemq/src/main/decaf/net" /F /Y 
xcopy "%ActiveMQInclude%/decaf/net/ssl/*.h" "../activemq/src/main/decaf/net/ssl" /F /Y 
xcopy "%ActiveMQInclude%/decaf/nio/*.h" "../activemq/src/main/decaf/nio" /F /Y 
xcopy "%ActiveMQInclude%/decaf/security/*.h" "../activemq/src/main/decaf/security" /F /Y 
xcopy "%ActiveMQInclude%/decaf/security/auth/x500/*.h" "../activemq/src/main/decaf/security/auth/x500/" /F /Y 
xcopy "%ActiveMQInclude%/decaf/security/cert/*.h" "../activemq/src/main/decaf/security/cert" /F /Y 
xcopy "%ActiveMQInclude%/decaf/util/*.h" "../activemq/src/main/decaf/util" /F /Y 
xcopy "%ActiveMQInclude%/decaf/util/comparators/*.h" "../activemq/src/main/decaf/util/comparators" /F /Y 
xcopy "%ActiveMQInclude%/decaf/util/concurrent/*.h" "../activemq/src/main/decaf/util/concurrent" /F /Y 
xcopy "%ActiveMQInclude%/decaf/util/concurrent/atomic/*.h" "../activemq/src/main/decaf/util/concurrent/atomic" /F /Y 
xcopy "%ActiveMQInclude%/decaf/util/concurrent/locks/*.h" "../activemq/src/main/decaf/util/concurrent/locks" /F /Y 
xcopy "%ActiveMQInclude%/decaf/util/logging/*.h" "../activemq/src/main/decaf/util/logging" /F /Y 
xcopy "%ActiveMQInclude%/decaf/util/zip/*.h" "../activemq/src/main/decaf/util/zip" /F /Y 

xcopy "%ActiveMQWin32DebugLib%/*.dll" "../activemq/vs2010-build/Win32/DebugDLL" /F /Y
xcopy "%ActiveMQWin32DebugLib%/*.lib" "../activemq/vs2010-build/Win32/DebugDLL" /F /Y  

xcopy "%ActiveMQWin32ReleaseLib%/*.dll" "../activemq/vs2010-build/Win32/ReleaseDLL" /F /Y
xcopy "%ActiveMQWin32ReleaseLib%/*.lib" "../activemq/vs2010-build/Win32/ReleaseDLL" /F /Y  

xcopy "%ActiveMQX64DebugLib%/*.dll" "../activemq/vs2010-build/x64/DebugDLL" /F /Y
xcopy "%ActiveMQX64DebugLib%/*.lib" "../activemq/vs2010-build/x64/DebugDLL" /F /Y  

xcopy "%ActiveMQX64ReleaseLib%/*.dll" "../activemq/vs2010-build/x64/ReleaseDLL" /F /Y
xcopy "%ActiveMQX64ReleaseLib%/*.lib" "../activemq/vs2010-build/x64/ReleaseDLL" /F /Y  

pause