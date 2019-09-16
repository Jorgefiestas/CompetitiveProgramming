#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int T, spf[N];

void sieve(){
    for(int i = 1; i<= N; i++){
        spf[i] = i;
    }

    for(int i = 2; i <= N; i++){
        if(spf[i] != i) continue;
        for(int j = i*i; j <= N; j += i){
            if(spf[j] == j)
                spf[j] = i;
        }
    }
}

int solve(int s, int t){
    queue<int> q;
    bool vis[N] = {false};
    vector<int> dis(N, -1);

    q.push(s);
    dis[s] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr >= t) break;
        int tn = curr;
        if(spf[tn] == tn) continue;
        while(tn != 1){
            if(curr + spf[tn] <= t && !vis[curr + spf[tn]]){
                vis[curr + spf[tn]] = true;
                dis[curr + spf[tn]] = dis[curr] + 1;
                q.push(curr + spf[tn]);
            }
            tn /=  spf[tn];
        }
    }
    return dis[t];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    cin>>T;
    int s, t;
    for(int i = 1; i <= T; i++){
        cin>>s>>t;
        cout<<"Case "<<i<<": "<<solve(s, t)<<endl;
    }
    return 0;
}
