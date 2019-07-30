#include <string.h>
#include <iostream>
bool match(char* str, char* pattern);
bool matchcore(char* str, char* pattern);

bool match(char* str, char* pattern)
{
    if(str==NULL || pattern ==NULL){
        return false;
    }
    return matchcore(str,pattern);
}
    
bool matchcore(char* str,char* pattern){
    if(*str=='\0' && *pattern=='\0'){
        return true;
    }
    if(*str!='\0' && *pattern=='\0'){
        return false;
    }
    //if(str=='\0' && pattern!='\0')的时候还不确定
    if(*(pattern+1)=='*'){
        if(*str==*pattern || (*pattern=='.' && *str!='\0')){
            //这时候就有多种选择
            //matchcore(str,pattern+2)就是忽略.*
            //matchcore(str+1,pattern+2)匹配一个
            //matchcore(str+1,pattern).*匹配多个
            return matchcore(str,pattern+2) || matchcore(str+1,pattern+2) || matchcore(str+1,pattern);
        }
        else{
            //*str!=*pattern
            return matchcore(str,pattern+2);
        }
    }
    if(*str==*pattern || (*pattern=='.' && *str!='\0')){
        return matchcore(str+1,pattern+1);
    }
    //当*str!=*pattern
    return false;
}
int main(){
    std::cout<<match(nullptr,".*")<<std::endl;
    std::cout<<match("aaa","a.a")<<std::endl;
    std::cout<<match("bcd","b.*")<<std::endl;
}