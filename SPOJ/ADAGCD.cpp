#include <bits/stdc++.h>
#define N 100000000
#define mod 1000000007;
using namespace std;

typedef unordered_map<long long, int> um;

int n, s, t;
int spf[N+1];
int fact[10000001];
unordered_set<long long> curr;

void sieve(){
    for(int i = 0; i<=N; i++){
        spf[i] = i;
    }
    for(int i = 2; i*i<=N; i++){
        if(spf[i] != i) continue;
        for(int j = i*i; j<=N; j += i){
            if(spf[j] != j) continue;
            spf[j] = i;
        }
    }
}

void addPrimeFactors(int m, um &temp){
    while(m > 1){
        temp[spf[m]]++;
        m /= spf[m];
    }
}

long long exp(long long x, int y){
    int res = 1;
    while(y > 0){
        if(y & 1) res = (res*x)%mod;
        y >>= 1;
        x = (x*x)%mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    cin>>n>>s;
    for(int i = 0; i<s; i++){
        cin>>t;
        while(t > 1){
            fact[spf[t]]++;
            curr.insert(spf[t]);
            t /= spf[t];
        }
    }

    for(int i = 1; i<n; i++){
        cin>>s;
        um temp;
        for(int j = 0; j<s; j++){
            cin>>t;
            addPrimeFactors(t, temp);
        }
        unordered_set<long long> to_erase;
        for(long long x : curr){
            fact[x] = min(fact[x], temp[x]);
            if(fact[x] == 0) to_erase.insert(x);
        }
        for(long long x : to_erase){
            curr.erase(x);
        }
    }

    long long g = 1;
    for(long long x : curr){
        g = (g*exp(x, fact[x]))%mod;
    }
    cout<<g<<endl;
    return 0;
}
