#include <bits/stdc++.h>
using namespace std;
long long T, n, m;

long long calc(long long x){
    if(x == 2)
        return n + 1;
    if(x == 3)
        return 2*n;
    return n + (x - 1)*n/2;
}

long long solve(){
    cin>>n>>m;

    if(m < n - 1 || m > n*(n + 1)/2)
        return -1;
    if(n == 1 && m == 0)
        return 0;
    if(n == 1 && m == 1)
        return 1;
    if(n == 2){
        if(m < 2)
            return 1;
        else 
            return 2;
    }

    long long l = 2, r = n, me;
    while(l <= r){
        me = (l + r)/2;
        if(calc(me) >= m && calc(me - 1) < m)
            return me;

        if(calc(me) < m)
            l = me + 1;

        else
            r = me - 1;
    }

    return 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int i = 0; i < T; i++)
        cout<<solve()<<endl;

    return 0;
}
