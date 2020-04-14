#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, a[N];
int mem1[N][N], mem2[N];
bool vis[N][N];

int dp(int l, int r) {
	if (l + 1 == r) {
		return a[l];
	}
	if (vis[l][r]) {
		return mem1[l][r];
	}
	vis[l][r] = true;

	int ans = 0;
	for (int m = l + 1; m < r; m++) {
		if (dp(l, m) && dp(l, m) == dp(m, r)) {
			ans = dp(l, m) + 1;
			break;
		}
	}

	return mem1[l][r] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(mem2, 1, sizeof mem2);
	mem2[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!dp(i, j)) continue;
			mem2[j] = min(mem2[j], mem2[i] + 1);
		}
	}

	cout << mem2[n] << '\n';

	return 0;
}
