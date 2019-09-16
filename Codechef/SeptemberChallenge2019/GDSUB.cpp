#include <bits/stdc++.h>
using namespace std;
long long k, n, t, ans, cnt[8005], mem[8005][8005];
const long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    k = min(k, 8000LL);

    for(int i = 0; i < n; i++){
        cin>>t;
        cnt[t]++;
    }

    for(int i = 1; i <= 8000; i++){
        mem[1][i] = (mem[1][i - 1] + cnt[i])%mod;
    }

    for(int i = 2; i <= k; i++){
        for(int j = i; j <= 8000; j++){
            mem[i][j] = (mem[i][j - 1] + mem[i - 1][j - 1]*cnt[j])%mod;
        }
    }

    for(int i = 1; i <= k; i++)
        ans = (ans + mem[i][8000])%mod;

    cout<<ans + 1<<endl;
    return 0;
}
