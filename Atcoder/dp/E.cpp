#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int W = 1e9;
int n, c, v[105];
long long w[105], mem[105][N];
bool vis[105][N];

long long dp(int idx, int val) {
	if (val <= 0) {
		return 0;
	}
	if (idx == n) {
		return W + 1;
	}
	if (vis[idx][val]) {
		return mem[idx][val];
	}
	vis[idx][val] = true;

	long long ans = dp(idx + 1, val);
	ans = min(ans, w[idx] + dp(idx + 1, val - v[idx]));

	return mem[idx][val] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	int V = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		V += v[i];
	}

	int ans = 0;
	for (int i = 0; i <= V; i++) {
		if (dp(0, i) > c) continue;
		ans = i;
	}

	cout << ans << '\n';

	return 0;
}
