#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k, a[N], prv[N];
bool blocked[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int si;
	for (int i = 0; i < m; i++) {
		cin >> si;
		blocked[si] = true;
	}

	int lst = -N;
	for (int i = 0; i < n; i++) {
		lst = blocked[i] ? lst : i;
		prv[i] = lst;
	}

	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}

	long long ans = LLONG_MAX;
	for (int p = 1; p <= k; p++) {
		long long can = 0;

		for (int i = 0; i < n; i += p) {
			if (prv[i] + p <= i) {
				can = -1;
				break;
			}
			i = prv[i];
			can += (long long) a[p];
		}

		if (can >= 0) {
			ans = min(ans, can);
		}
	}

	if (ans == LLONG_MAX) {
		ans = -1;
	}

	cout << ans << '\n';

	return 0;
}
