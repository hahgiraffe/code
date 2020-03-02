/*
 * @Author: haha_giraffe
 * @Date: 2020-02-13 17:40:57
 * @Description: 
 */
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>

int main(){
    int fd;
    
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("socket error\n");
    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_port = htons(9999);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(fd,(struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1){
        printf("bind error, %s\n", strerror(errno));
        exit(1);
    }
    
    if (listen(fd, 10) <0){
        printf("listen error\n");
        exit(1);
    }
    while(1){
        int clientfd;
        struct sockaddr_in clientaddr;
        socklen_t len;
        if((clientfd = accept(fd, (sockaddr*)&clientaddr, &len) ) < 0){
            printf("accept error");
        }
        // msghdr buf;
        // int recvnum = recvmsg(clientfd, &buf, NULL);
        // printf("get msg %s, len %d", buf.msg_iov)
        char buf[4096];
        int recvnum = read(clientfd, &buf, 4096);
        printf("content %s, len %d\n",buf, recvnum);
        // sprintf(tmp,"content %s, len %d\n",buf, recvnum)
        write(clientfd, buf, 4096);
        close(clientfd);
        sleep(1);
    }
    close(fd);
    return 0;
}