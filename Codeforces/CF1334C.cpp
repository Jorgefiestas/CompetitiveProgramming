#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n;
long long a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	long long d = a[0] - max(0LL, a[0] - b[n - 1]);
	long long ov = a[0];
	int di = 0;
	a[0] = max(0LL, a[0] - b[n - 1]);

	for (int i = 1; i < n; i++) {
		long long dt = a[i] - max(0LL, a[i] - b[i - 1]);
		if (dt < d) {
			di = i;
			d = dt;
			ov = a[i];
		}
		a[i] = max(0LL, a[i] - b[i - 1]);
	}
	a[di] = ov;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
