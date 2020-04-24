#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 250;
const int K = (1 << 7) + 10;
int n, m, k, w[N];
int dp[K][N];
pii tran[K][N];
vector<int> edg[N];
char mat[N][N];

void trace(int bm, int v) {
	mat[v / m][v % m] = 'X';
	int sm = tran[bm][v].first;
	int u = tran[bm][v].second;
	if (sm) {
		trace(sm, u);
	}
	if (sm && bm != sm) {
		trace(bm ^ sm, u);
	}
}

int main() {
	cin >> n >> m >> k;
	
	int num = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = i * m + j;
			cin >> w[v];

			if (i) edg[v].push_back(v - m);
			if (j) edg[v].push_back(v - 1);
			if (i < n - 1) edg[v].push_back(v + m);
			if (j < m - 1) edg[v].push_back(v + 1);
			mat[i][j] = '.';
		}
	}

	memset(dp, 1, sizeof dp);

	for (int i = 0; i < k; i++) {
		int xi, yi;
		cin >> xi >> yi;
		xi--, yi--;

		int v = xi * m + yi;

		dp[(1 << i)][v] = w[v];
	}


	for (int bm = 1; bm < (1 << k); bm++) {
		for (int v = 0; v < num; v++) {
			for (int sm = bm & (bm - 1); sm; sm = (sm - 1) & bm) {
				int tans = dp[sm][v] + dp[bm ^ sm][v] - w[v];
				if (tans < dp[bm][v]) {
					dp[bm][v] = tans;
					tran[bm][v] = {sm, v};
				}
			}

		}

		for (int i = 0; i < num; i++) {
			for (int v = 0; v < num; v++) {
				for (int u : edg[v]) {
					int tans = dp[bm][v] + w[u];
					if (tans < dp[bm][u]) {
						dp[bm][u] = tans;
						tran[bm][u] = {bm, v};
					}
				}
			}
		}
	}

	int cmp = (1 << k) - 1;
	int opt =  min_element(dp[cmp], dp[cmp] + num) - dp[cmp];

	cout << dp[cmp][opt] << '\n';
	trace(cmp, opt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}

	return 0;
}
