#include <bits/stdc++.h>
using namespace std;
int q, n, k, t;

int solve(){
    cin>>n>>k;

    int mx = 0;
    int mn = INT_MAX;

    for(int i = 0; i < n; i++){
        cin>>t;
        mx = max(mx, t);
        mn = min(mn, t);
    }

    if(mx - k > mn + k)
        return -1;

    return mn + k;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int i = 0; i < q; i++){
        cout<<solve()<<endl;
    }

    return 0;
}
