#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, root[51];

int findRoot(int i){
    while(i != root[i]){
        root[i] = root[root[i]];
        i = root[i];
    }
    return i;
}

void join(int i, int j){
    root[findRoot(i)] = findRoot(j);
}

int main(){
    cin>>n>>m;
    for(int i = 0; i<n; i++)
        root[i] = i;

    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        a--, b--;
        join(a, b);
    }
    
    ans = 1LL<<n;
    for(int i = 0; i<n; i++){
        if(root[i] == i) ans >>=1;
    }

    cout<<ans<<endl;
    return 0;
}
