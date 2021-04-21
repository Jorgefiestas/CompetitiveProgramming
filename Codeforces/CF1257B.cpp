#include <bits/stdc++.h>
using namespace std;
int t, x, y;

bool solve() {
	cin >> x >> y;

	if (x > 3) {
		return true;
	}
	if (x > 1) {
		return y <= 3;
	}
	return y == 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
