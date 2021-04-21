#include <bits/stdc++.h>
using namespace std;
int t, c[4];

bool solve() {
	for (int i = 0; i < 4; i++) {
		cin >> c[i];
	}

	int ev = 0;
	for (int i = 0; i < 4; i++) {
		if (c[i] % 2 == 0) {
			ev += 1;
		}
	}

	if (ev >= 3) {
		return true;
	}

	ev = 0;
	for (int i = 0; i < 3; i++) {
		if (!c[i]) return false;
		if (c[i] % 2) {
			ev += 1;
		}
	}
	if (c[3] % 2) {
		ev += 1;
	}

	return ev >= 3;
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
