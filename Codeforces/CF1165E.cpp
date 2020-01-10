#include <bits/stdc++.h>
using namespace std;
long long n, a[200001], b[200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>a[i];
    for(int i = 0; i<n; i++)
        cin>>b[i];
    
    for(long long i = 0; i<n; i++)
        a[i] *= (i+1)*(n-i);

    sort(a, a+n);
    sort(b, b+n, [](long long x, long long y){return x>y;});
    
    long long ans = 0;
    for(int i = 0; i<n; i++)
        ans = (ans + ((a[i]%998244353)*b[i])%998244353)%998244353;
    
    cout<<ans<<endl;
    return 0;
}
