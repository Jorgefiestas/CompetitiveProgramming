#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long N, fact[200001];

long long exp(long long x, int y){
    int res = 1;
    while(y > 0){
        if(y & 1) res = (res*x)%mod;
        y >>= 1;
        x = (x*x)%mod;
    }
    return res;
}

long long factorial(long long x){
    if(x < 2) return 1;
    if(fact[x]) return fact[x];
    return fact[x] = (x*factorial(x-1))%mod;
}

int main(){
    while(cin>>N){
        long long sum = 0;
        for(int n = 1; n < N; n++){
            sum = (sum + exp(n, N-n-1)*exp(N-n, n-1))%mod;
        }
        cout<<(sum*factorial(N))%mod<<endl;
    }
    return 0;
}
