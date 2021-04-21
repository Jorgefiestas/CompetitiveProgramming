#include <bits/stdc++.h>
using namespace std;
int t, x, y, k, n;

bool solve() {
	cin >> x >> y >> k >> n;

	if (x % k != y % k)
		return false;

	int nx = x / k;
	int ny = y / k;

	return nx % 2 == ny % 2;
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
