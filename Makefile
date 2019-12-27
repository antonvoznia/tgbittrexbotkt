INC=-I /home/anton/jdk-12.0.1/include/ -I /home/anton/jdk-12.0.1/include/linux/

CFLAGS=-fPIC -shared
TARGET_LIB=libapi.so
all:	hello.c
	g++ hello.c logs.cpp bitt_api.cpp api_request.cpp $(CFLAGS) $(INC) -o $(TARGET_LIB) -lcurl
