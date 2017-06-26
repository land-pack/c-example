# path to lua source headers
INC= /home/frank/ak/redis/redis-3.2.0/deps/lua/src/lua.h


all: ktime.so
 
ktime.so: ktime.c
	gcc -I $(INC) -O3 -fPIC -o ktime.o -c ktime.c
	gcc -shared -O3 ktime.o -o ktime.so

test:
	lua ./test_ktime.lua

clean:
	rm *.o
	rm *.so
