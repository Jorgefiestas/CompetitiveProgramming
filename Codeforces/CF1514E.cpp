#include <bits/stdc++.h>
using namespace std;

bool query1(int a, int b) {
	cout << 1 << ' ' << a << ' ' << b << endl;
	int ans;
	cin >> ans;

	if (ans == -1)
		exit(0);
	return ans;
}

bool query2(int x, vector<int> &v) {
	cout << 2 << ' ' << x << ' ' << v.size() << ' ';

	for (int x : v) {
		cout << x << ' ';
	}
	cout << endl;

	int ans;
	cin >> ans;

	if (ans == -1)
		exit(0);
	return ans;
}

void solve() {
	int n;
	cin >> n;

	vector<int> path;
	vector<vector<bool>> mat(n, vector<bool>(n, 1));

	for (int i = 0; i < n; i++) {
		path.push_back(i);
	}

	stable_sort(path.begin(), path.end(), query1);

	vector<int> vq;
	for (int i = 0; i < n - 1; i++) {
		vq.push_back(path[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (i == vq.size() - 1) {
			for (int j = i + 1; j < n; j++) {
				for (int k = 0; k <= i; k++) {
					mat[path[j]][path[k]] = 0;
				}
			}
			vq.pop_back();
		}

		while (!vq.empty() && query2(path[i], vq)) {
			vq.pop_back();
		}
	}

	cout << 3 << endl;
	for (int v = 0; v < n; v++) {
		for (int u = 0; u < n; u++) {
			cout << mat[v][u];
		}
		cout << endl;
	}

	int ver;
	cin >> ver;
	if (ver == -1)
		exit(0);
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
