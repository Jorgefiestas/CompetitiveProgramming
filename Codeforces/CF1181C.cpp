#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
string mat[N];

struct Flag {
	int l = 0;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
};

Flag flag[N][N];

bool operator ==(Flag &a, Flag &b) {
	bool l = a.l == b.l;
	bool c1 = a.c1 == b.c1;
	bool c2 = a.c2 == b.c2;
	bool c3 = a.c3 == b.c3;
	return l && c1 && c2 && c3;
}

int check(int i, int j, int l) {
	if (i < 0 || i + l > n) {
		return false;
	}

	for (int k = i + 1; k < i + l; k++) {
		if (mat[k][j] != mat[i][j]) {
			return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i - 1][j] == mat[i][j]) continue;
			int l = 1;
			while (i + l < n && mat[i + l][j] == mat[i][j]) {
				l++;
			}

			if (check(i - l, j, l) && check(i + l, j, l)) {
				flag[i][j].l = l;
				flag[i][j].c1 = mat[i - 1][j];
				flag[i][j].c2 = mat[i][j];
				flag[i][j].c3 = mat[i + l][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!flag[i][j].l) continue;

			int k = 0;
			while (k < m && flag[i][j + k] == flag[i][j]) {
				k++;
				ans += k;
			}

			j = j + k - 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
