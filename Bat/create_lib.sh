cd /data/coding/Libs

#! 编译boost库
version="1.83.0" 
boost_dir="boost_1_83_0" 

if [ ! -f /data/coding/Libs/boost_installed.txt ]; then

	if [ ! -f ${boost_dir}.tar.gz ]; then
		wget https://archives.boost.io/release/${version}/source/${boost_dir}.tar.gz
	fi 
	
	tar -zxvf ${boost_dir}.tar.gz
	rm -rf boost
	mv ${boost_dir} boost
	cd boost
	./bootstrap.sh --with-libraries=all --with-toolset=gcc
	./b2 install --prefix=/data/coding/Libs/boost/stage/ cxxflags="-std=c++20"
	touch /data/coding/Libs/boost_installed.txt
	
fi


ace_config="/data/coding/Libs/ACE/ACE_wrappers/ace/config.h"
ace_platform_macros_gnu="/data/coding/Libs/ACE/ACE_wrappers/include/makeinclude/platform_macros.GNU"

if [ ! -f /data/coding/Libs/ace_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/ace_installed_clone.txt ]; then
	
		rm -rf ACE
	 
		wget -O /data/coding/Libs/ACE-8.0.2.tar.gz https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-8_0_2/ACE-8.0.2.tar.gz
 
		
		# 检查下载是否成功
		if [ $? -eq 0 ]; then
			# 解压下载的文件
			tar -xzf /data/coding/Libs/ACE-8.0.2.tar.gz -C /data/coding/Libs/ACE

			# 检查解压是否成功
			if [ $? -eq 0 ]; then
				# 创建标志文件
				touch /data/coding/Libs/ace_installed_clone.txt 
			else
				echo "解压失败"
			fi
		else
			echo "下载失败"
		fi
	
	fi 
	
	if [ -f /data/coding/Libs/ace_installed_clone.txt ]; then
	
		# 创建新的 config.h 文件
		echo "#ifndef _CONFIG_H_" > "$ace_config"
		echo "#define _CONFIG_H_" >> "$ace_config"
		echo "#include \"ace/config-linux.h\"" >> "$ace_config"
		echo "#endif" >> "$ace_config"

		# 创建新的 platform_macros.GNU 文件
		echo "include /data/coding/Libs/ACE/ACE_wrappers/include/makeinclude/platform_linux.GNU" > "$ace_platform_macros_gnu"	
	
		export ACE_ROOT="/data/coding/Libs/ACE/ACE_wrappers"
	
		cd /data/coding/Libs/ACE/ACE_wrappers		
		 
		make
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/ace_installed.txt
	
		fi
	
	fi
	
fi  


if [ ! -f /data/coding/Libs/mongo-cxx-driver_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/mongo-cxx-driver_installed_clone.txt ]; then
	
		rm -rf mongo-cxx-driver

		git clone https://github.com/mongodb/mongo-cxx-driver.git
		
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/mongo-cxx-driver_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/Libs/mongo-cxx-driver_installed_clone.txt ]; then
	
		cd /data/coding/Libs/mongo-cxx-driver
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release
		make
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/mongo-cxx-driver_installed.txt
	
		fi
	
	fi
	
fi 


if [ ! -f /data/coding/Libs/mysql_connector_cpp_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/mysql_connector_cpp_installed_clone.txt ]; then
	
		rm -rf mysql-connector-c++

		git clone https://github.com/mysql/mysql-connector-cpp.git mysql-connector-c++
		
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/mysql_connector_cpp_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/Libs/mysql_connector_cpp_installed_clone.txt ]; then
	
		cd /data/coding/Libs/mysql-connector-c++
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release
		make 
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/mysql_connector_cpp_installed.txt
	
		fi
	
	fi
	
fi



if [ ! -f /data/coding/Libs/activemq_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/activemq_installed_clone.txt ]; then
	
		rm -rf activemq
		rm -rf activemq-cpp

		git clone https://github.com/apache/activemq-cpp
		
		mv /data/coding/Libs/activemq-cpp/activemq-cpp/ /data/coding/Libs/activemq/
		
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/activemq_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/Libs/activemq_installed_clone.txt ]; then
	
		cd /data/coding/Libs/activemq
	
		sh ./build.sh configure
		./configure
		make
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/activemq_installed.txt
	
		fi
	
	fi
	
fi 


if [ ! -f /data/coding/Libs/miniz_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/miniz_installed_clone.txt ]; then
	
		rm -rf miniz

		git clone https://github.com/richgel999/miniz
		
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/miniz_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/Libs/miniz_installed_clone.txt ]; then
	
		cd /data/coding/Libs/miniz
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release
		make 
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/miniz_installed.txt
	
		fi
	
	fi
	
fi


if [ ! -f /data/coding/Libs/hiredis_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/hiredis_installed_clone.txt ]; then
	
		rm -rf hiredis

		git clone https://github.com/redis/hiredis
		
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/hiredis_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/Libs/hiredis_installed_clone.txt ]; then
	
		cd /data/coding/Libs/hiredis
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release
		make 
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/hiredis_installed.txt
	
		fi
	
	fi
	
fi

if [ ! -f /data/coding/Libs/protobuf_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/protobuf_installed_clone.txt ]; then
	
		rm -rf protobuf

		git clone https://github.com/protocolbuffers/protobuf.git
		
		if [ $? -eq 0 ]; then 
		
			cd protobuf
            git checkout v21.12
			git submodule update --init --recursive
            cd ..
	 
			touch /data/coding/Libs/protobuf_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/Libs/protobuf_installed_clone.txt ]; then
	
		cd /data/coding/Libs/protobuf
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release
		make 
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/protobuf_installed.txt
	
		fi
	
	fi
	
fi

