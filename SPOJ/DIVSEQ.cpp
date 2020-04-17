#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = 1e9 + 9;
int n, K;
int dp[N][N];
vector<int> divisors[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

void sieve() {
	for (int i = 1; i < N; i++) {
		for (int j = i; j <= N; j += i) {
			divisors[j].emplace_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> n >> K;

	for (int i = 1; i <= K; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int k = 1; k <= K; k++) {
			for (int d : divisors[k]) {
				dp[i][k] = add(dp[i][k], dp[i - 1][d]);
			}
			for (int j = 2 * k; j <= K; j += k) {
				dp[i][k] = add(dp[i][k], dp[i - 1][j]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= K; i++) {
		ans = add(ans, dp[n - 1][i]);
	}
	
	cout << ans << endl;
}
