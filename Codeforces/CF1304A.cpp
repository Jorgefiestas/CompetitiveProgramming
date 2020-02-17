#include <bits/stdc++.h>
using namespace std;
int t, x, y, a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> x >> y >> a >> b;
		
		int t = (y - x) / (a + b);

		if ((y - x) % (a + b) != 0) {
			cout << -1 << '\n';
			continue;
		}

		cout << t << '\n';
	}

	return 0;
}
