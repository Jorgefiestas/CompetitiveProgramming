#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e6;
const long long mod = 1e9 + 7;
int n, a[25][25];
long long mem[25][N];
bool vis[25][N];

long long dp(int idx, int bm) {
	if (bm == 0) {
		return 1;
	}
	if (idx == n) {
		return 0;
	}
	if (vis[idx][bm]) {
		return mem[idx][bm];
	}
	vis[idx][bm] = true;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (!(bm & (1 << i)) || !a[idx][i]) continue;
		ans = (ans + dp(idx + 1, bm & ~(1 << i))) % mod;
	}

	return mem[idx][bm] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << dp(0, (1 << n) - 1) << '\n';

	return 0;
}
