#include <bits/stdc++.h>
using namespace std;
int n, t, sum, mx;

int main(){
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>t;
        mx = max(mx, t);
        sum += t;
    }

    cout<<n*mx - sum<<endl;
    
    return 0;
}
