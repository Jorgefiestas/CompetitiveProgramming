#include <bits/stdc++.h>
using namespace std;
int T, n, s[500];

bool  solve(){
    cin>>n;
    n = 4*n;

    for(int i = 0; i < n; i++)
        cin>>s[i];

    sort(s, s + n);
    if(s[0] != s[1] || s[n - 1] != s[n - 2])
        return false;

    long long a = s[0]*s[n-1];

    for(int i = 1; i < n/4; i++){
        if(s[i*2] != s[i*2 + 1])
            return false;
        if(s[n - 1 - i*2] != s[n - 2 - i*2])
            return false;

        long long ta = s[i*2] * s[n - 1 - i*2];
        if(a != ta)
            return false;
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
