#include <bits/stdc++.h>
using namespace std;
int T, n, k, b, h[200];

bool solve(){
    cin>>n>>b>>k;
    for(int i = 0; i < n; i++)
        cin>>h[i];

    for(int i = 0; i < n - 1; i++){
        int ll = max(h[i + 1] - k, 0);

        if(h[i] >= ll){
            b += h[i] - ll;
        }
        else{
            if(b < ll - h[i])
                return false;
            b -= (ll - h[i]);
        }
    }

    return true;
}

int main(){
    cin>>T;
    while(T--){
        if(solve())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
