#include <bits/stdc++.h>
using namespace std;
int n, m, ds[500005], size[500005];

int root(int i){
    while(ds[i] != i){
        ds[i] = ds[ds[i]];
        i = ds[i];
    }
    return i;
}

bool find(int i, int j){
    return root(i) == root(j);
}

void join(int i, int j){
    size[root(j)] += size[root(i)];
    ds[root(i)] = root(j);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;

    for(int i = 0; i<n; i++){
        ds[i] = i;
        size[i] = 1;
    }

    for(int i = 0; i<m; i++){
        int s, t, rt;
        cin>>s;
        for(int j = 0; j<s; j++){
            cin>>t;
            t--;
            if(j == 0) rt = root(t);
            if(!find(t, rt)){
                join(t, rt);
            }
        }
    }
    for(int i = 0; i<n; i++)
        cout<<size[root(i)]<<" ";
    cout<<endl;
    return 0;
}
