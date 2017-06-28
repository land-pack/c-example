# path to lua source headers
# INC= /home/frank/ak/redis/redis-3.2.0/deps/lua/src/lua.h


all: mmap_example.out
 
mmap_example.out: mmap_example.c
	gcc -o mmap_example.out mmap_example.c 

test:
	./mmap_example.out

clean:
	rm *.out
