#include <bits/stdc++.h>
using namespace std;
int t;
long long q;
long long subfact[10000001];
const long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    subfact[0] = 1;
    subfact[1] = 0;

    for(int i = 2; i<=10000000; i++){
        subfact[i] = (i-1)*(subfact[i-1] + subfact[i-2])%mod;
    }

    cin>>t;
    while(t--){
        cin>>q;
        cout<<subfact[q]<<endl;
    }
}
