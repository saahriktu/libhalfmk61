ifeq ($(prefix),)
	prefix=/usr
endif
ifeq ($(shell which $(CXX)),)
	CXX=g++
endif
ifeq ($(libdir),)
	libdir=$(prefix)/lib
endif
all:
	$(CXX) -c -fPIC $(CXXFLAGS) -o halfmk61.o halfmk61.cpp
	$(CXX) -fPIC -shared $(CXXFLAGS) -o libhalfmk61.so.1 halfmk61.o
	ln -s libhalfmk61.so.1 libhalfmk61.so
install:
	install -pDm644 libhalfmk61.so $(DESTDIR)$(libdir)/libhalfmk61.so
	install -pDm644 libhalfmk61.so.1 $(DESTDIR)$(libdir)/libhalfmk61.so.1
	install -pDm644 halfmk61.hpp $(DESTDIR)$(prefix)/include/halfmk61/halfmk61.hpp
clean:
	rm libhalfmk61.so.1 libhalfmk61.so halfmk61.o
