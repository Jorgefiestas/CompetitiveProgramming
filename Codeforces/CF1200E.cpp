#include <bits/stdc++.h>
using namespace std;

long long n;
string expr, str;
vector<long long> hashed_expr(1000005), hashed_str(1000005);

const long long x = 103;
const long long MOD = 1000000007;

long long cid(char x){
    if(x >= 'A' && x <= 'Z')
        return x - 'A' + 11;
    else if(x >= 'a' && x <= 'z')
        return ('Z' - 'A' + 12) + x - 'a';
    return x - '0' + 1;
}

void str_hash(string &s, vector<long long> &v){
    long long a = 1;

    for(int i = 1; i <= s.size(); i++){
        v[i] = (v[i - 1] + cid(s[i - 1]) * a) % MOD;
        a = (a * x) % MOD;
    }
}

long long fpow(long long m, long long y){
    long long res = 1;
    while(y > 0){
        if(y & 1) res = (res * m) % MOD;
        y >>= 1;
        m = (m * m) % MOD;
    }

    return res;
}

long long inv(long long m){
    return fpow(m, MOD - 2);
}
        
int main(){
    cin>>n>>expr;
    str_hash(expr, hashed_expr);

    long long a0 = fpow(x, expr.size());
    for(int i = 0; i < n - 1; i++){
        cin>>str;
        str_hash(str, hashed_str);

        long long l;
        long long a = x;

        for(l = min(expr.size(), str.size()); l > 0; l--){
            long long substr_a = ((hashed_expr[expr.size()] - hashed_expr[expr.size() - l]) % MOD + MOD) % MOD;
            substr_a = (substr_a * inv(fpow(x, expr.size() - l))) % MOD;
            if(substr_a == hashed_str[l]) break;
        }

        for(int j = l; j < str.size(); j++){
            expr += str[j];
            hashed_expr[expr.size()] = (hashed_expr[expr.size() - 1] + cid(str[j]) * a0) % MOD;
            a0 = (a0 * x) % MOD;
        }
    }

    cout<<expr;
    return 0;
}
