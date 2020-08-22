/*
 * @Author: haha_giraffe
 * @Date: 2020-08-16 22:38:59
 * @Description: 
 */
#include <iostream>
union bigEnd_smallEnd
{
    int a;
    char c[4];
};


template <typename T>
T myfunc(T a, T b){
    return a + b;
}

int main(){
    bigEnd_smallEnd b;
    b.a = 0x12345678;
    if(b.c[0] == 0x12){
        std::cout << "bigend" << std::endl;
    } else if(b.c[0] == 0x78){
        std::cout << "smallend" << std::endl;
    }

    int anum = 3;
    int bnum = 4;
    long long tmp = myfunc(anum, bnum);
    std::cout << tmp;
}
