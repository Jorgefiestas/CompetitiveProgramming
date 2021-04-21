#include <bits/stdc++.h>
using namespace std;
int t, n;

int solve() {
	cin >> n;

	int a, x;
	cin >> a;

	bool eq = true;
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (x != a) {
			eq = false;
		}
	}

	return eq ? n : 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
