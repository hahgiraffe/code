/*
 * @Author: haha_giraffe
 * @Date: 2020-03-06 19:30:08
 * @Description: memmove实现
 */
#include <string.h>
#include <stdio.h>

void* mymemmove(void* dst, void* src, int n){
    //如果没有冲突
    char* tmpdst = (char*)dst;
    char* tmpsrc = (char*)src;
    if(tmpdst <= tmpsrc || tmpdst >= tmpsrc + n){
        while(n--){
            *tmpdst++ = *tmpsrc++;
        }
    }
    else {
        tmpdst = tmpdst + n - 1;
        tmpsrc = tmpsrc + n - 1;
        while(n--){
            *tmpdst-- = *tmpsrc--;
        }
    }

    return dst;
} 

int main(){
    char src[5] = "sdfa";
    char dst[10];
    char* ptr = src;
    // memmove(dst, ptr, sizeof(ptr));
    mymemmove(dst, src, sizeof(src));
    printf("%s %s\n", src, dst);    
    return 0;
}