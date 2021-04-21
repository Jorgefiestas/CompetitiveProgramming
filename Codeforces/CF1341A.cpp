#include <bits/stdc++.h>
using namespace std;
int t, n, a, b, c, d;

bool solve() {
	cin >> n >> a >> b >> c >> d;

	int l1 = n * (a - b);
	int r1 = n * (a + b);

	return l1 <= c + d && c - d <= r1;
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
