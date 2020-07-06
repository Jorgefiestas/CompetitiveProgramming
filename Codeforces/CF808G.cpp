#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
string s, t;

struct PrefixAutomaton {
	int a[N][26];
	int p[N];

	PrefixAutomaton() {
		memset(p, 0, sizeof p);
		memset(a, -1, sizeof a);
	}

	void build(const string &str) {
		for (int i = 1; i < str.size(); i++) {
			int j = p[i - 1];
			while (j > 0 && str[i] != str[j]) {
				j = p[j - 1];
			}
			if (str[i] == str[j]) {
				j++;
			}
			p[i] = j;
		}

		for (int state = 0; state < str.size(); state++) {
			int i = str[state] - 'a';
			a[state][i] = state + 1;
		}
	}

	int go(int state, char c) {
		int i = c - 'a';
		if (a[state][i] == -1) {
			a[state][i] = state ? go(p[state - 1], c) : 0;
		}
		return a[state][i];
	}
} pa;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	n = s.size();
	m = t.size();

	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof dp);

	pa.build(t);

	dp[n][m] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= m; j++) {
			if (j == m) {
				dp[i][j] += 1;
			}

			if (s[i] != '?') {
				int nj = pa.go(j, s[i]);
				dp[i][j] += dp[i + 1][nj];
				continue;
			}

			int mx = 0;
			for (int c = 'a'; c <= 'z'; c++) {
				int nj = pa.go(j, c);
				mx = max(dp[i + 1][nj], mx);
			}

			dp[i][j] += mx;
		}
	}

	cout << dp[0][0] << '\n';

	return 0;
}
