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
	./b2 install --prefix=/data/coding/Libs/boost/stage/
	touch /data/coding/Libs/boost_installed.txt
	
fi 