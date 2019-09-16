#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000;
long long n, q, k, t, arr[N + 5];
unordered_map<long long, long long> cnt;
vector<vector<int>> js(N + 5);

long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

long long count_elements(){
    long long i, ans = 0;
    for(i = 1; i*i < k; i++){
        if(k%i == 0){
            ans += cnt[i];
            ans += cnt[k/i];
        }
    }

    if(i*i == k)
        ans += cnt[i];

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(long long i = 0; i < n; i++)
        cin>>arr[i];

    js[0].push_back(0);
    cnt[arr[0]]++;
    for(long long i = 1; i < n; i++){
        long long g = arr[i];
        long long idx = i;
        js[i].push_back(i);

        long long ng;
        for(int x : js[i - 1]){
            ng = gcd(g, arr[x]);
            if(g == ng) continue;
            cnt[g] += idx - x;
            g = ng;
            idx = x;
            js[i].push_back(x);
        }

        cnt[g] += idx + 1;
    }

    cin>>q;
    for(long long i = 0; i < q; i++){
        cin>>k;
        cout<<count_elements()<<endl;
    }

    return 0;
}
