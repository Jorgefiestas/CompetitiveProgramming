#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], c[N][3];
int mem[N][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c[i][0] >> c[i][1] >> c[i][2];
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (k == j) continue;
				mem[i][j] = max(mem[i][j], mem[i + 1][k] + c[i][k]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 3; i++) {
		ans = max(ans, mem[0][i]);
	}

	cout << ans << '\n';

	return 0;
}
