#include <bits/stdc++.h>
using namespace std;
int n, t, a, s, sa;
vector<int> pp;

int main(){
    cin>>n>>a;
    s += a;
    sa += a;

    pp.push_back(1);
    for(int i = 2; i<=n; i++){
        cin>>t;
        if(a >= 2*t){
            pp.emplace_back(i);
            sa += t;
        }
        s += t;
    }

    if(sa > s/2){
        cout<<pp.size()<<endl;
        for(int x : pp)
            cout<<x<<" ";
        cout<<endl;
    }
    else
        cout<<0<<endl;

    return 0;
}
