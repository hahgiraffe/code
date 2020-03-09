/*
 * @Author: haha_giraffe
 * @Date: 2020-03-06 20:46:35
 * @Description: memcopy实现
 */
#include <stdio.h>

// void* mymemcopy(void* dst, void* src, int n ){
//     char* d = (char*)dst;
//     char* s = (char*)src;
//     while(n--){
//         *d++ = *s++;
//     }
//     return dst;
// }

// int main(){
//     char a[10] = "asdafafas";
//     char b[10];
//     mymemcopy(b, a, sizeof(a));
//     printf("%s\n", b);
//     return 0;
// }


class myclass{
public:
    virtual void myfunc(){

    }
private:
    char mychar;
};

union myunion
{
    int a;
    char c[4];
};

int main(){
    myunion u;
    u.a = 0x12345678;
    if(u.c[0] == 0x12){
        printf("大端，网络字节序，高字节在低地址\n");
    } else {
        printf("小端，主机字节序，高字节在高地址\n");
    }
    return 0;
}