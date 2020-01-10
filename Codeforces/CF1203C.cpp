#include <bits/stdc++.h>
using namespace std;
long long n, g, t, c;

long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    cin>>g;

    for(int i = 0; i < n - 1; i++){
        cin>>t;
        g = gcd(g, t);
    }

    long long i;
    for(i = 1; i*i < g; i++){
        if(g%i == 0)
            c += 2;
    }

    if(i*i == g)
        c++;

    cout<<c<<endl;

    return 0;
}

