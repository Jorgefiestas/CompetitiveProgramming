#include <bits/stdc++.h>
using namespace std;
const int N = 3050;
int n;
double p[N], mem[N][N];
bool vis[N][N];

double dp(int idx, int w) {
	if (w == 0) {
		return 1;
	}
	if (idx == n) {
		return 0;
	}
	if (vis[idx][w]) {
		return mem[idx][w];
	}
	vis[idx][w] = true;

	double ans = 0;
	ans += dp(idx + 1, w) * (1 - p[idx]);
	ans += dp(idx + 1, w - 1) * p[idx];

	return mem[idx][w] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> p[i];
	}

	cout << setprecision(11) << dp(0, (n + 1) / 2) << '\n';

	return 0;
}
