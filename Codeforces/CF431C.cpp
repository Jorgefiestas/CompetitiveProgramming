#include <bits/stdc++.h>
using namespace std;
int n, k, d;
const int mod = 1e9 + 7;

unordered_map<int, unordered_map<bool, long long>> mem;

long long dp( int sum, int s){
    if(sum == n && s) return 1;
    if(sum >= n) return 0;
    if(mem.find(sum) != mem.end())
        if(mem[sum].find(s) != mem[sum].end()) return mem[sum][s];
    long long cnt = 0;
    for(int i = 1; i<=k; i++)
        cnt = (cnt + dp(sum + i, s || i >= d))%mod;
    return mem[sum][s] = cnt;
}

int main(){
    cin>>n>>k>>d;
    cout<<dp(0, false)<<endl;
    return 0;
}
