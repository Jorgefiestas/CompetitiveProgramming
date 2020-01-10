#include <bits/stdc++.h>
using namespace std;
int n;
long long ans, a[10000], b[10000];
unordered_map<long long, long long> cnt;
unordered_map<long long, int> cnt_size;

bool comp(long long x, long long y){
    if(y > x)
        return false;

    while(y){
        if(x & 1){
            x >>= 1;
            y >>= 1;
            continue;
        }

        if(y & 1)
            return false;
        x >>= 1;
        y >>= 1;
    }

    return true;
}

int main(){
    cin>>n;

    for(int i = 0; i < n; i++)
        cin>>a[i];

    for(int i = 0; i < n; i++)
        cin>>b[i];

    for(int i = 0; i < n; i ++){
        cnt[a[i]] += b[i];
        cnt_size[a[i]]++;
    }

    for(auto it : cnt){
        if(cnt_size[it.first] > 1)
            continue;

        for(auto jt : cnt){
            if(cnt_size[jt.first] < 2)
                continue;
            
            if(comp(jt.first, it.first)){
                cnt[jt.first] += it.second;
                cnt_size[jt.first]++;
                break;
            }
        }
    }

    for(auto it : cnt){
        if(cnt_size[it.first] < 2)
            continue;
        
        ans += it.second;
    }

    cout<<ans<<endl;

    return 0;
}
