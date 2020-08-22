<!--
 * @Author: haha_giraffe
 * @Date: 2019-11-07 21:00:51
 * @Description: 
 -->
# kmp的模板
给定两个字符串：字符串a是目标串，字符串b是模式串，返回a中完全匹配b的第一个index,如果找不到则返回-1    
kmp的时间复杂度O(m+n)
```cpp

vector<int> findnext(string b){
    vector< int> next;
    next.push_back(-1);
    int i=0,k=-1;
    while(i< b.size()-1){
        if(k==-1 || b[i]==b[k]){
            i++;
            k++;
            next.push_back(k);
        }
        else{
            k=next[k];
        }
    }
    return next;
}
int kmp(string a, string b){
    if(b.empty()){
        return 0;   //这里可以再讨论
    }
    int n=a.size();
    int m=b.size();
    int i=0,j=0;
    vector< int> next = findnext(b);
    while(i< n && j< m){
        if(j==-1 || a[i] == b[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j==m){
        return i-j;
    }
    return -1;
}

```