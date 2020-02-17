#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000000003;
long long num[6];

long long posmod(long long x){
    return (mod + x%mod)%mod;
}

long long mod_mult(long long a, long long b){
    a = posmod(a);
    b = posmod(b);

    long long res = 0;
    while(b){
        if(b&1) res = (res+a)%mod;
        a = (a<<1)%mod;
        b >>= 1;
    }

    return res;
}

long long mod_pow(long long x, long long y){
    x = posmod(x);

    long long res = 1;
    while (y){ 
        if (y & 1) 
            res = mod_mult(x, res); 
        y = y>>1; 
        x = mod_mult(x, x);   
    } 
    return res; 
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]>>num[5]){
        long long x1, x2, x3, x1p, x2p;
        long long a = 1;
        long long b = 0;
        bool solved = false;

        for(int i = 0; i<4; i++){
            x1 = num[i];
            x2 = num[i+1];
            x3 = num[i+2];
            x1p = mod_pow(x1, mod-2);

            if(x1 == 0 || mod_mult(x2, x1p) == 1)
                continue;

            b = mod_mult(mod_mult(x2, mod_mult(x2,x1p)) - x3, mod_pow(mod_mult(x1p,x2) - 1, mod - 2));
            a = mod_mult(x2 - b, x1p);
            solved = true;
            break;
        }

        for(int i = 0; i<4 && !solved; i++){
            x1 = num[i];
            x2 = num[i+1];
            x3 = num[i+2];
            x2p = mod_pow(x2, mod-2);

            if(x2 == 0 || mod_mult(x1, x2p) == 1)
                continue;

            b = mod_mult(mod_mult(x3, mod_mult(x1, x2p)) - x2, mod_pow(mod_mult(x2p,x1) - 1, mod - 2));
            a = mod_mult(x3 - b, x2p);
            solved = true;
        }

        cout<<posmod(mod_mult(a, num[5]) + b)<<endl;
    }
    return 0;
}
