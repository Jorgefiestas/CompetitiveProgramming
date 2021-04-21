#include <bits/stdc++.h>
using namespace std;
int t, n;

void solve() {
	cin >> n;

	if (n <= 30) {
		cout << "NO\n";
		return;
	}

	int last = n - 30;

	int a = 6;
	int b = 10;
	int c = 14;

	if (last == a || last == b || last == c) {
		last -= 1;
		c += 1;
	}

	cout << "YES\n";
	cout << a << ' ' << b << ' ' << c << ' ' << last << '\n';
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
