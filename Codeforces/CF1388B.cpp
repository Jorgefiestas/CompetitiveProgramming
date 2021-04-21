#include <bits/stdc++.h>
using namespace std;
int t, n;

void solve() {
	cin >> n;

	int n8 = (n + 3) / 4;
	int n9 = n - n8;
	for (int i = 0; i < n9; i++) {
		cout << '9';
	}
	for (int i = 0; i < n8; i++) {
		cout << '8';
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
