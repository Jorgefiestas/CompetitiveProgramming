#include <bits/stdc++.h>
using namespace std;
int n, k[1000006], freq[1000006];
vector<int> gifts[1000006];
const long long mod = 998244353;

long long gcd(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

long long exp(long long x, long long y) {
	long long ans = 1;

	while (y) {
		if (y & 1) {
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		y >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i ++){ 
		cin >> k[i];
		int temp;
		for (int j = 0; j < k[i]; j++) {
			cin >> temp;
			gifts[i].emplace_back(temp);
			freq[temp]++;
		}
	}

	long long num = 0;
	long long den = 1;

	for (int i = 0; i < n; i ++) {
		num = (num * k[i]) % mod;
		for (int g : gifts[i]) {
			num = (num + freq[g] * den) % mod;
		}
		den = (den * k[i]) % mod;
	}

	den = (den * n) % mod;
	den = (den * n) % mod;

	cout << (num % mod * exp(den, mod - 2)) % mod << endl;
	
	return 0;
}
