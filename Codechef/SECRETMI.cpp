#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int L = 1e4 +  5;
int n, m, l, w[N][N], d[N][N], b[L];

int solve() {
	cin >> n >> m >> l;

	for (int i = 0; i < l; i++) {
		cin >> b[i];
	}

	memset(d, -1, sizeof d);
	memset(w, 0, sizeof w);

	int ai, bi, wi;
	for (int i = 0; i < m; i++) {
		cin >> ai >> bi >> wi;
		w[ai][bi] = wi;
		w[bi][ai] = wi;
		d[ai][bi] = wi;
		d[bi][ai] = wi;
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == -1 || d[k][j] == -1) continue;
				if (d[i][j] == -1) {
					d[i][j] = d[i][k] + d[k][j];
				}
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = 1;

	int s = b[0];
	int td = 0;
	for (int i = 1; i < l; i++) {
		int v = b[i];
		int u = b[i - 1];

		if (!w[u][v] || w[u][v] > d[u][v]) {
			return -1;
		}

		td += d[b[i]][b[i - 1]];
		if (td != d[s][b[i]]) {
			ans++;
			s = b[i - 1];
			td = d[b[i]][b[i - 1]];
		}
	}
	ans++;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
