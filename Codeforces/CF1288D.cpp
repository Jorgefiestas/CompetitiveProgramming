#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
const int M = 8;
const int M2 = (1 << M);
int n, m, a[N][M], idx[M2];

int idxi, idxj;

bool check(int x) {
	set<int> bms;

	for (int i = 0; i < n; i++) {
		int bm = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] < x) continue;
			bm |= (1 << j);
		}
		bms.insert(bm);
		idx[bm] = i + 1;
	}

	for (int a : bms) {
		for (int b : bms) {
			if ((a | b) == (1 << m) - 1) {
				idxi = idx[a];
				idxj = idx[b];
				return true;
			}
		}
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int l = 0;
	int r = 1e9;

	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		if (check(m)) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << idxi << ' ' << idxj << '\n';

	return 0;
}
