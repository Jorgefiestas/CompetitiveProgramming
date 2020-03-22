#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
const long long mod = 1e9 + 7;
int h, w;
long long mem[N][N];
bool vis[N][N];
char mat[N][N];

long long dp(int i, int j) {
	if (i == h && j == w) {
		return 1;
	}
	if (vis[i][j]) {
		return mem[i][j];
	}
	vis[i][j] = true;
	long long ans = 0;

	if (i < h && mat[i + 1][j] == '.') {
		ans = (ans + dp(i + 1, j)) % mod;
	}

	if (j < w && mat[i][j + 1] == '.') {
		ans = (ans + dp(i, j + 1)) % mod;
	}

	return mem[i][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> mat[i][j];
		}
	}

	cout << dp(1, 1) << '\n';

	return 0;
}
