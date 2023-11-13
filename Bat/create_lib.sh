cd /data/github/Libs

#! 编译boost库
version="1.83.0" 
boost_dir="boost_1_83_0" 

if [ ! -f /data/github/Libs/boost_installed.txt ]; then

	if [ ! -f ${boost_dir}.tar.gz ]; then
		wget https://boostorg.jfrog.io/artifactory/main/release/${version}/source/${boost_dir}.tar.gz
	fi 
	
	tar -zxvf ${boost_dir}.tar.gz
	rm -rf boost
	mv ${boost_dir} boost
	cd boost
	./bootstrap.sh --with-libraries=all --with-toolset=gcc
	./b2 install --prefix=/data/github/Libs/boost/stage/
	touch /data/github/Libs/boost_installed.txt
	
fi 