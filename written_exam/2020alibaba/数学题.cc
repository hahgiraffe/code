/*
 * @Author: haha_giraffe
 * @Date: 2020-03-24 17:44:04
 * @Description: 
 */
// C(1,n)*1 + C(2,n)*2 + ... + C(n,n)*n推出n*2^(n-1)
#include <iostream>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;

ll mod_pow(ll x, ll n){
    ll ans = 1;
    while(n > 0){
        if(n & 1){
            ans = ans * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    ll tmp = mod_pow(2, n-1);
    return 0;
}