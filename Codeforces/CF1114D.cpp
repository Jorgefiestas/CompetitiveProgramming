#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, c[N], mem[N][N][2];
bool vis[N][N][2];

int dp(int l, int r, int s) {
	if (l == 0 && r == n - 1) {
		return 0;
	}
	if (vis[l][r][s]) {
		return mem[l][r][s];
	}
	vis[l][r][s] = true;

	int col = s ? c[l] : c[r];
	int ans = INT_MAX;

	if (l > 0) {
		if (c[l - 1] == col) {
			ans = min(ans, dp(l - 1, r, s));
		}
		else  {
			ans = min(ans, 1 + dp(l - 1, r, 1));
		}
	}

	if (r < n - 1) {
		if (c[r + 1] == col) {
			ans = min(ans, dp(l, r + 1, s));
		}
		else  {
			ans = min(ans, 1 + dp(l, r + 1, 0));
		}
	}

	return mem[l][r][s] = ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		ans = min(ans, dp(i, i, 0));
	}

	cout << ans << '\n';

	return 0;
}
