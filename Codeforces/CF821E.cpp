#include <bits/stdc++.h>
using namespace std;
const int N = 16;
const int mod = 1e9 + 7;
int n, c, ways[N], mat[N][N];
long long k;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

void copymat(int a[N][N], int b[N][N]) {
	for (int i = 0; i <= c; i++) {
		for (int j = 0; j <= c; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void matmul(int res[N][N], int a[N][N], int b[N][N]) {
	int ans[N][N];
	for (int i = 0; i <= c; i++) {
		for (int j = 0; j <= c; j++) {
			ans[i][j] = 0;
			for (int k = 0; k <= c; k++) {
				ans[i][j] = add(ans[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}

	copymat(res, ans);
}

void matexp(int res[N][N], int x[N][N], long long y) {
	int ans[N][N];
	memset(ans, 0, sizeof ans);

	for (int i = 0; i <= c; i++) {
		for (int j = 0; j <= c; j++) {
			ans[i][j] = (i == j) ? 1 : 0;
		}
	}

	while (y) {
		if (y & 1) {
			matmul(ans, ans, x);
		}
		matmul(x, x, x);
		y >>= 1;
	}

	copymat(res, ans);
}

void updatemat() {
	memset(mat, 0, sizeof mat);

	for (int i = 0; i <= c; i++) {
		for (int j = max(0, i - 1); j <= min(c, i + 1); j++) {
			mat[i][j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	ways[0] = 1;

	long long a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		b = min(b, k);
		long long len = b - a;

		updatemat();
		matexp(mat, mat, len);

		int nways[N];
		for (int i = 0; i <= c; i++) {
			nways[i] = 0;
			for (int j = 0; j <= c; j++) {
				nways[i] = add(nways[i], mul(mat[i][j], ways[j]));
			}
		}

		memset(ways, 0, sizeof ways);
		for (int i = 0; i <= c; i++) {
			ways[i] = nways[i];
		}
	}

	cout << ways[0] << '\n';

	return 0;
}
