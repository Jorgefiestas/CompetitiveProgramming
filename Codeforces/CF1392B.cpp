#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, a[N];
long long k;

void solve() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sp = (k % 2LL) ? 1 : 2;
	for (int i = 0; i < sp; i++) {
		int mx = *max_element(a, a + n);
		for (int j = 0; j < n; j++) {
			a[j] = mx - a[j];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
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
