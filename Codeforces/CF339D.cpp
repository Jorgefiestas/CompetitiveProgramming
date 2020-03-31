#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m, a[20][N];
int summary[N];

void update(int p, int i) {
	if (p % 2) {
		a[p][i] = a[p - 1][i * 2 - 1] | a[p - 1][i * 2];
	}
	else {
		a[p][i] = a[p - 1][i * 2 - 1] ^ a[p - 1][i * 2];
	}

	if (p < n) {
		update(p + 1, (i + 1) / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= (1 << n); i++) {
		cin >> a[0][i];
	}
	
	for (int p = 1; p <= n; p++) {
		for (int i = 1; i <= (1 << (n - p)); i++) {
			if (p % 2) {
				a[p][i] = a[p - 1][i * 2 - 1] | a[p - 1][i * 2];
			}
			else {
				a[p][i] = a[p - 1][i * 2 - 1] ^ a[p - 1][i * 2];
			}
		}
	}

	int pi, bi;
	for (int i = 0; i < m; i++) {
		cin >> pi >> bi;

		a[0][pi] = bi;
		update(1, (pi + 1) / 2);

		cout << a[n][1] << '\n';
	}
	
	return 0;
}
