#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], nxt[N];
long long k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	nxt[n] = n + 1;
	for (int i = n - 1; i > 0; i--) {
		nxt[i] = (a[i + 1] > 1) ? i + 1 : nxt[i + 1];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		long long prod = 1;
		long long sum = 0;
		int j = i;

		for (int it = 0; j <= n && it < 60; it++) {
			if (LLONG_MAX / prod <= a[j]) break;

			prod *= (long long) a[j];
			sum += (long long) a[j];

			long long ones = nxt[j] - j - 1;
			if (prod % k == 0) {
				long long den = prod / k;
				if (sum <= den && den <= sum + ones) {
					ans += 1;
				}
			}

			sum += ones;
			j = nxt[j];
		}
	}

	cout << ans << '\n';

	return 0;
}
