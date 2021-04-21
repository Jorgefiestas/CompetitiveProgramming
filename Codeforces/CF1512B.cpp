#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<string> mat(n);
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	vector<int> r, c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == '.') continue;
			r.push_back(i);
			c.push_back(j);
		}
	}

	if (r[0] == r[1]) {
		r[1] = (r[0] + 1) % n;
	}
	if (c[0] == c[1]) {
		c[1] = (c[0] + 1) % n;
	}

	mat[r[1]][c[1]] = '*';
	mat[r[0]][c[1]] = '*';
	mat[r[1]][c[0]] = '*';

	for (int i = 0; i < n; i++) {
		cout << mat[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
