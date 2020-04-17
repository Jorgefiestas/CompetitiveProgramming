#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int t, n;
long long phi[N], dp[N];

void sieve() {
	phi[1] = 1;
	for (long long i = 2; i < N; i++) {
		if (phi[i]) continue;
		phi[i] = i - 1;
		for (long long j = i * 2; j < N; j += i) {
			if (!phi[j]) {
				phi[j] = j;
			}
			phi[j] = (phi[j] * (i - 1)) / i;
		}
	}

	dp[1] = 1;
	for (long long i = 2; i < N; i++) {
		dp[i]++;
		for (long long j = i; j < N; j += i) {
			dp[j] += (phi[i] * i) / 2;
		}
		dp[i] *= i;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
