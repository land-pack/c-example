#include <stdio.h>
#include <stdlib.h>


typedef struct epoll_filefd{
    struct file * file;
    int fd;
} __packed;


static inline int ep_cmp_ffd( struct epoll_filefd * p1,
                              struct epoll_filefd *p2){

    return (p1->fd > p2->fd ? +1:
        (p1->fd < p2->fd ? -1: p1->fd - p2->fd));
}


static inline int ep_find(){

    volatile 
    register 
    auto

    return 0;
}


int main(int argc, char * argv[]){

    struct epoll_filefd *p1 = (struct epoll_filefd*)malloc(sizeof(struct epoll_filefd));
    struct epoll_filefd *p2 = (struct epoll_filefd*)malloc(sizeof(struct epoll_filefd));
    p1->fd = 9;
    p2->fd = 10;
    printf("%d\n",ep_cmp_ffd(p1, p2));
    p1->fd = 10;
    p2->fd = 9;
    printf("%d\n",ep_cmp_ffd(p1, p2));
    p1->fd = 9;
    p2->fd = 9;
    printf("%d\n",ep_cmp_ffd(p1, p2));
    return 0;
}
