#include <bits/stdc++.h>
using namespace std;
long long q, n;

long long f(long long x){
    long long sol = 0;

    while(x%5 == 0){
        sol += 3;
        x /= 5;
    }
    while(x%3 == 0){
        sol += 2;
        x /= 3;
    }
    while(x%2 == 0){
        sol += 1;
        x /= 2;
    }
    if(x > 1)
        return -1;
    return sol;
}

int main(){
    cin>>q;
    while(q--){
        cin>>n;
        cout<<f(n)<<endl;
    }
    return 0;
}
