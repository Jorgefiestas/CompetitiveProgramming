#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int t, n, m, x, y;
string mat[N], pat[N];
bool dp[N][N], ndp[N][N];

struct PrefixAutomaton {
	int a[105][26];
	int p[105];

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
};


int solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		cin >> pat[i];
	}

	for (int i = 0; i < x; i++) {
		PrefixAutomaton pa;
		pa.build(pat[i]);
		memset(ndp, 0, sizeof ndp);

		for (int j = 0; j < n; j++) {
			int state = 0;
			for (int k = 0; k < m; k++) {
				char c = mat[j][k];
				state  = pa.go(state, c);
				if (state == y && (dp[j - 1][k] || !i)) {
					ndp[j][k] = true;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				dp[j][k] = ndp[j][k];
			}
		}
	}

	int cnt = 0;
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) {
			if (!dp[j][k]) continue;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
