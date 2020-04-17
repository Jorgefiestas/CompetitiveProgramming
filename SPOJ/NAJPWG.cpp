#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
long long dp[N], phi[N];

void sieve() {
	for (long long i = 2; i <= N; i ++) {
		if (phi[i]) continue;
		phi[i] = i - 1;
		for (long long j = i + i; j <= N; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] = (phi[j] * (i - 1)) / i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	for (long long i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + (i - phi[i]);
	}

	cin >> t;

	int q;
	for (int i = 1; i <= t; i++) {
		cin >> q;
		cout << "Case " << i << ": " << dp[q] << '\n';
	}

	return 0;
}
