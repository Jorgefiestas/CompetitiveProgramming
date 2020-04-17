#include <bits/stdc++.h>
using namespace std;
long long h, w;
long long mod = 998244353;

long long exp(long long x, long long y) { 
    long long res = 1;   

    while (y > 0){ 
        if (y & 1) res = (res * x)%mod; 
   
        y = y>>1;
        x = (x*x)%mod; 
    } 

    return res; 
}

int main(){
    cin>>w>>h;
    long long ans = (exp(2, h) * exp(2, w))%mod; 

    cout<<ans<<endl;
    return 0;
}
