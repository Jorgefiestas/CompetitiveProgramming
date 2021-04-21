#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int t, n, a[N];

int lp2(int x) {
	int p2 = 31 - __builtin_clz(x);
	return 1 << p2;
}

void solve() {
	cin >> n;

	long long s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		cout << lp2(a[i]) << ' ';
	}
	cout << '\n';
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
