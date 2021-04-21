#include <bits/stdc++.h>
using namespace std;
int t, n;

bool solve() {
	cin >> n;

	char c;
	int cnt = 120 - n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		cnt += (c == '1');
	}

	return cnt >= 90;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
