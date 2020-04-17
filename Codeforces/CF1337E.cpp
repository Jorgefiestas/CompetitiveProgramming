#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int mod = 998244353;
int n, m;
string s, t;
int mem[N][N];
bool vis[N][N];

int add(int x, int y) {
	if (x + y > mod) {
		return x + y - mod;
	}
	return x + y;
}

int dp(int i, int j) {
	if (vis[i + 1][j]) {
		return mem[i + 1][j];
	}
	if (i == -1 && j == n) {
		return 1;
	} 
	vis[i + 1][j] = true;

	int si = j - i - 1;
	int ans = 0;
	if (j >= m && i == -1) {
		ans = 1;
	}

	bool l = false;
	bool r = false;
	if (i >= m) {
		ans = add(ans, dp(i - 1, j));
	}
	else if (i >= 0 && s[si] == t[i]) {
		l = true;
		ans = add(ans, dp(i - 1, j));
	}

	if (j < m && s[si] == t[j]) {
		r = true;
		ans = add(ans, dp(i, j + 1));
	}
	else if (j >= m && j < n) {
		ans = add(ans, dp(i, j + 1));
	}
	
	return mem[i + 1][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	n = s.size();
	m = t.size();

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (s[0] != t[i]) continue;
		ans = add(ans, dp(i - 1, i + 1));
	}
	for (int i = m; i < n; i++) {
		ans = add(ans, dp(i - 1, i + 1));
	}
	ans = add(ans, ans);

	cout << ans << '\n';

	return 0;
}
