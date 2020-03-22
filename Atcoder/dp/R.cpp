#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const long long mod = 1e9 + 7;
int n;

void copy(long long a[N][N], long long b[N][N]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void mult_mat(long long a[N][N], long long b[N][N]) {
	long long c[N][N];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = 0;
			for (int k = 0; k < n; k++) {
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
			}
		}
	}
	
	copy(a, c);
}

void mat_exp(long long m[N][N], long long k) {
	
	long long ans[N][N];
	for (int i = 0; i < n; i++) {
		ans[i][i] = 1;
	}

	while (k) {
		if (k & 1) {
			mult_mat(ans, m);
		}
		mult_mat(m, m);
		k >>= 1;
	}

	copy(m, ans);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long k, mat[N][N];

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	mat_exp(mat, k);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = (ans + mat[i][j]) % mod;
		}
	}

	cout << ans << '\n';

	return 0;
}
