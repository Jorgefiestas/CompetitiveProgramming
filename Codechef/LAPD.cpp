#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int T, A, B, C;

long long count_less(int ks){
    long long ans = C;
    int l = INT_MAX;
    int k = ks * ks;

    for(int i = 1; i <= ks; i++){
	int t = k / i;
        if(i <= A - 1) {
            ans += min(t + 1,  C);
    	}
        if(t <= A - 1){
            if(l <= A - 1) {
                ans += (l - t) *1ll* min(i, C);
            }
            else {
                ans += (A - 1 - t) *1ll* min(i, C);
    	    }
        }
        l = t;
    }

    return ans;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &A, &B, &C);
		long long ans = 0;
		for(int b = 1; b <= B; b++){
			ans += count_less(b);
		}
		printf("%d\n", (A*1ll*B%mod*C%mod + mod - ans%mod) % mod);
    }
    return 0;
}
