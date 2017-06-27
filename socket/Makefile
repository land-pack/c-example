# path to lua source headers
# INC= /home/frank/ak/redis/redis-3.2.0/deps/lua/src/lua.h


all: epoll_socket.out
 
epoll_socket.out: epoll_socket.c
	gcc -o epoll_socket.out epoll_socket.c
	gcc -o block_server.out block_server.c
	gcc -o block_server_fork.out block_server_fork.c

test:
	./epoll_socket.exe

clean:
	rm *.out
