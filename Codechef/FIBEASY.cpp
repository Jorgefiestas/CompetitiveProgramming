#include <bits/stdc++.h>
using namespace std;
long long T, N;
unordered_map<long long, int> f;

long long cp2(long long x){
    long long ans = 0;
    while(x){
        ans++;
        x >>= 1;
    }
    return (1LL<<(ans - 1LL));
}

int fib(long long n) { 
    if(f.find(n) != f.end())
        return f[n];
    if (n == 0)
        return f[n] = 0;
    if (n == 1 || n == 2) 
        return f[n] = 1; 
  
    long long k = (n & 1)? (1 + n)>>1 : n>>1; 
  
    if(n & 1)
        f[n] = fib(k)*fib(k) + fib(k-1)*fib(k-1);
    else
        f[n] = (2*fib(k-1) + fib(k))*fib(k); 

    f[n] = f[n]%10;
    return f[n]; 
} 

void solve(){
    cin>>N;
    cout<<fib(cp2(N) - 1)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int i = 0; i < T; i++)
        solve();

    return 0;
}
