#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int mod = 1e9 + 7;
int n, dp[N][N];
string str;

void inc(int &a, int b) {
	a += b;
	if (a > mod) {
		a -= mod;
	}
}

void dec(int &a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> str;

	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= len; i++) {
			bool grtr = (str[len - 2] == '<');
			int l = grtr ? i : 1;
			int r = grtr ? len - 1 : i - 1;
			inc(dp[len][i], dp[len - 1][r]);
			dec(dp[len][i], dp[len - 1][l - 1]);
			inc(dp[len][i], dp[len][i - 1]);
		}
	}

	cout << dp[n][n] << '\n';
	return 0;
}
