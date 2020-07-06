#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1e6 + 100;
int n, m, p[M];
int tran[M], dp[M], dist[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char d;
			cin >> d;
			dist[i][j] = (d == '1') ? 1 : 1000;
			if (i == j) {
				dist[i][j] = 0;
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> p[i];
		p[i]--;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	dp[0] = 1;
	tran[0] = -1;
	for (int i = 1; i < m; i++) {
		dp[i] = 1e6 + 5;
		for (int j = 1; j <= min(105, i); j++) {
			if (j != dist[p[i - j]][p[i]]) break;
			if (dp[i - j] + 1 < dp[i]) {
				tran[i] = i - j;
				dp[i] = dp[i - j] + 1;
			}
		}
	}

	vector<int> path;
	for (int i = m - 1; i != -1; i = tran[i]) {
		path.emplace_back(p[i] + 1);
	}
	reverse(path.begin(), path.end());

	cout << dp[m - 1] << '\n';
	for (int v : path) {
		cout << v << ' ';
	}
	cout << '\n';

	return 0;
}
