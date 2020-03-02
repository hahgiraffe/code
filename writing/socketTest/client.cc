/*
 * @Author: haha_giraffe
 * @Date: 2020-02-09 17:06:26
 * @Description: client
 */
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
int main(){
    int clientfd;
    if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("socket error\n");
    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    if(inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr) < 0){
        printf("inet_pton error\n");
        _exit(1);
    }
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9999);
    if( connect(clientfd,(struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
        printf("connect error\n");
    }
    char* buf = "hello web";
    write(clientfd,buf,sizeof(buf)+1);
    char recvbuf[1024];
    int num = read(clientfd,recvbuf, 1024);
    printf("content %s, len %d\n",recvbuf, num);
    close(clientfd);

}