#include <bits/stdc++.h>
using namespace std;
long long T, k, n, t;

long long C(long long N, long long K){
    if (K > N) return 0;
    if (K * 2LL > N) K = N-K;
    if (K == 0) return 1;

    long long result = N;
    for(long long i = 2; i <= K; ++i){ 
        result *= (N - i +1);
        result /= i;
    }
    return result;
}

void solve(){
    cin>>n>>k;
    long long A[101] = {0};

    for(int i = 0; i < n; i ++){
        cin>>t;
        A[t]++;
    }

    long long s = 0, i = 1;
    while(s + A[i] < k){
        s += A[i];
        i++;
    }

    cout<<C(A[i], k - s)<<endl;
}


int main(){
    cin>>T;
    for(int i = 0; i < T; i++)
        solve();
    return 0;
}
