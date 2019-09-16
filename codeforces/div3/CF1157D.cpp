#include <bits/stdc++.h>
using namespace std;
long long n, k, s, offset, m, los;

int main(){
    cin>>n>>k;
    s = k*(k + 1)/2;

    if(n < s){
        cout<<"NO"<<endl;
        return 0;
    }

    while(n >= s + k){
        s += k;
        offset++;
    }
    
    m = n - s;

    if(k > 1 && offset == 0 && m == k - 1){
        if(k < 4){
            cout<<"NO"<<endl;
            return 0;
        }
        los = 1;
        m--;
    }

    cout<<"YES"<<endl;

    int i;
    for(i = 1; i <= k - m; i++)
        cout<<i + offset<<" ";
    for(; i < k; i++)
        cout<<i + offset + 1 <<" ";
    if(m) cout<<k + offset + 1 + los<<" ";
    cout<<endl;

    return 0;
}
