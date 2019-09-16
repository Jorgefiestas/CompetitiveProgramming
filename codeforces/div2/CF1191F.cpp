#include <bits/stdc++.h>
using namespace std;
long long n, x, y, ans, l, r, ll, lr;
bool flag;
pair<long long, long long> coor[200005];
long long N = 1000000005;
unordered_map<long long, long long> bit;
unordered_map<long long, bool> vis;

void insert(int m){
    while(m < N){
        bit[m]++;
        m += m & -m;
    }
}

long long num(int m){
    long long ans = 0;
    while(m){
        if(bit.find(m) != bit.end())
            ans += bit[m];
        m -= m & -m;
    }
    return ans;
}

int main(){

    scanf("%lld", &n);
    for(long long i = 0; i<n; i++){
        scanf("%lld %lld", &coor[i].second, &coor[i].first);
    }
    
    auto comp = [](pair<long long, long long> &a, pair<long long, long long> &b){
        return a.first > b.first ? true : a.first < b.first ? false : a.second < b.second;
    };

    sort(coor, coor + n, comp);

    long long lasty = -1;
    long long lastd;

    for(long long i = 0; i < n; i++){
        x = coor[i].second;
        y = coor[i].first;
        flag = vis[x];

        if(!flag){
            insert(coor[i].second);
            vis[x] = true;
        }

        l = num(x);
        r = num(N) - l + 1;
        ans += l*r;
        if(y == lasty){
            ll = lastd;
            lr = r - 1;
            if(flag) lr++;
            ans -= ll*lr;
        }
        lasty = y;
        lastd = l;
    }

    cout<<ans<<endl;

    return 0;
}
