#include <bits/stdc++.h>
using namespace std;
int t, n;
long long x;

void solve() {
	cin >> n >> x;

	long long mx = 0;
	long long mn = 0;

	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mx += (long long) (a + x - 1) / x;
		mn += a;
	}

	mn = (long long) (mn + x - 1) / x;
	cout << mn << ' ' << mx << endl;
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
