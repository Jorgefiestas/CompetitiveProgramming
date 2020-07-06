#include <bits/stdc++.h>
using namespace std;
long long q, k, n, a, b;

bool eval(long long x){
    return x*a + (n-x)*b < k;
}

int solve(){
    cin>>k>>n>>a>>b;

    long long l = 0;
    long long r = n;
    
    while(l <= r){
        long long m = (l + r)/2;
        
        if(eval(m)){
            if(m == n || !eval(m + 1))
                return m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int i = 0; i<q; i++){
        cout<<solve()<<endl;
    }

    return 0;
}
