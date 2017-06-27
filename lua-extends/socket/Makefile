# path to lua source headers
INC= /home/frank/ak/redis/redis-3.2.0/deps/lua/src/lua.h


all: ksocket.so
 
ksocket.so: ksocket.c
	gcc -I $(INC) -O3 -fPIC -o ksocket.o -c ksocket.c
	gcc -shared -O3 ksocket.o -o ksocket.so

test:
	lua ./test_ksocket.lua

clean:
	rm *.o
	rm *.so
