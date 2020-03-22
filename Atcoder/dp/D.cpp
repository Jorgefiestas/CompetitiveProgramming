#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, c, we[105], v[105];
long long mem[105][N];
bool vis[105][N];

long long dp(int idx, int w) {
	if (idx == n || w >= c) {
		return 0;
	}
	if (w + sumw[idx] <= c) {
		return sumv[idx];
	}
	if (vis[idx][w]) {
		return mem[idx][w];
	}
	vis[idx][w] = true;

	long long ans = dp(idx + 1, w);
	if (w + we[idx] <= c) {
		ans = max(ans, (long long) v[idx] + dp(idx + 1, w + we[idx]));
	}

	return mem[idx][w] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> we[i] >> v[i];
	}

	cout << dp(0, 0) << '\n';

	return 0;
}
