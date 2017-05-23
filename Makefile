all:
	g++ -c -fPIC -o halfmk61.o halfmk61.cpp
	g++ -fPIC -shared -o libhalfmk61.so halfmk61.o
install:
	cp libhalfmk61.so /usr/lib/
	mkdir /usr/include/halfmk61
	cp halfmk61.hpp /usr/include/halfmk61
