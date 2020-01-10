#include <bits/stdc++.h>
using namespace std;
int n, t, a[200005], c[200005];
multiset<int> b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>a[i], a[i] %= n;
    for(int i = 0; i<n; i++)
        cin>>t, b.insert(t%n);
    for(int i = 0; i<n; i++){
        auto it = b.lower_bound(n-a[i]);
        if(it == b.end()) it = b.begin();
        t = *it;
        c[i] = (a[i]+t)%n;
        b.erase(it);
    }
    for(int i = 0; i<n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}
