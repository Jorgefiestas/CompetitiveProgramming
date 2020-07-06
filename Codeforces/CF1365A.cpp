#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int t, n, m, row[N], col[N];
bool mat;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);

		cin >> n >> m;

		for (int i = 0;  i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat;
				row[i] |= mat;
				col[j] |= mat;
			}
		}

		int r = 0, c = 0;
		for (int i = 0; i < n; i++) {
			if (!row[i]) {
				r++;
			}
		}
		for (int i = 0; i < m; i++) {
			if (!col[i]) {
				c++;
			}
		}


		if (min(r, c) % 2) {
			cout << "Ashish\n";
		}
		else {
			cout << "Vivek\n";
		}
	}

	return 0;
}
