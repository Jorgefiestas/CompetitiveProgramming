#include <bits/stdc++.h>
using namespace std;
int n, a, b, m[11];
const int mod = 2004;

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int comb(int N, int r){

	int num = 1;
	int den = 1;

	for(int i = 1; i <= n; i ++)
		den *= i;

	
	for(int i = 0; i < n; i++){
		int x = N - i;
		int g = gcd(den, x);
		x /= g;
		den /= g;
		x %= mod;
		num = (num * x) % mod;
	}

	return num;
}

int solve(int k){
	if(k < 0)
		return 0;

	int ans  = 0;

	for(int mask = 0; mask < (1 << n); mask++){
		int kp = k;
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				kp -= m[i] + 1;
			}
		}
		if(kp >= 0){
			int temp = comb(kp + n, n);
			ans += (__builtin_popcount(mask)&1) ? mod - temp : temp;
			ans %= mod;
		}
	}

	return ans;
}

int main(){
	cin>>n>>a>>b;

	for(int i = 0; i < n; i++)
		cin>>m[i];

	cout<<(solve(b) + mod - solve(a - 1)) % mod<<endl;

	return 0;
}
