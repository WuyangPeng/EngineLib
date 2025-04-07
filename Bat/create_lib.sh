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


if [ ! -f /data/coding/Libs/ace_installed.txt ]; then

    cd /data/coding/Libs/
	
	if [ ! -f /data/coding/Libs/ace_installed_clone.txt ]; then
	
		rm -rf ACE
		rm -rf ACE_TAO

		git clone https://github.com/DOCGroup/ACE_TAO.git
		
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/ace_installed_clone.txt
			
			mv /data/coding/Libs/ACE_TAO/ACE /data/coding/Libs/ACE_TAO/ACE_wrappers
			mv /data/coding/Libs/ACE_TAO /data/coding/Libs/ACE
	
		fi 
	
	fi 
	
	if [ -f /data/coding/Libs/ace_installed_clone.txt ]; then
	
		cd /data/coding/Libs/ACE
	
		mkdir -p build
		cd build

		cmake ..
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

		cmake ..
		make
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/Libs/mongo-cxx-driver_installed.txt
	
		fi
	
	fi
	
fi 