#include <bits/stdc++.h>
using namespace std;
int t, n, m, tc;
string str, tar;
short mem[401][401][401];
short vis[401][401][401];

int dp(int i, int j1, int j2) {
	if (i == n) {
		if (j2 == m) {
			return 0;
		}
		return -1;
	}

	if (vis[i][j1][j2] == tc) {
		return mem[i][j1][j2];
	} 

	vis[i][j1][j2] = tc;

	if (tar[j1] != str[i] && tar[j2] != str[i]) {
		return mem[i][j1][j2] = dp(i + 1, j1, j2);
	}

	int ans = -1;

	if (j1 < m && str[i] == tar[j1]) {
		int d = dp(i + 1, j1 + 1, j2);
		ans = (d >= 0) ? (d + 1) : -1;
	}
	if (j2 < m && str[i] == tar[j2]) {
		int d = dp(i + 1, j1, j2 + 1);
		ans = max(ans, d);
	}

	return mem[i][j1][j2] = ans;
}

void solve() {
	cin >> str >> tar;

	n = str.size();
	m = tar.size();

	for (int i = 0; i < m; i++) {
		int l = dp(0, 0, i);
		if (l >= i) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		tc++;
		solve();
	}

	return 0;
}
