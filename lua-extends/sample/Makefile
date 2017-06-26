# path to lua source headers
INC= /home/frank/ak/redis/redis-3.2.0/deps/lua/src/lua.h


all: hey.so
 
hey.so: hey.c
	gcc -I $(INC) -O3 -fPIC -o hey.o -c hey.c
	gcc -shared -O3 hey.o -o hey.so

test:
	lua ./heytest.lua

clean:
	rm *.o
	rm *.so
