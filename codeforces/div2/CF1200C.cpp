#include <bits/stdc++.h>
using namespace std;
long long n, m, q, g;

long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

long long sector(long long x, long long y){
    if(x == 1){
        return (y - 1)/(n/g);
    }
    return (y - 1)/(m/g);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>q;
    g = gcd(n, m);

    long long x1, y1, x2 ,y2;
    for(int i = 0; i < q; i++){
        cin>>x1>>y1>>x2>>y2;

        if(sector(x1, y1) == sector(x2, y2))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
