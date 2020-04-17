#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n;
vector<int> divisors[N];
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

	dp[1] = 0;
	for (long long i = 1; i < N; i++) {
		for (long long j = 2 * i; j < N; j += i) {
			dp[j] += i * phi[j / i];
		}
		dp[i] += dp[i - 1];
	}

}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	while (cin >> n, n) {
		cout << dp[n] << '\n';
	}

	return 0;
}
