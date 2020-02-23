#include <bits/stdc++.h>
using namespace std;
int t, a, b, x, y;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> a >> b >> x >> y;

		int ans = 0;
		ans = max(ans, (a - 1 - x) * b);
		ans = max(ans, (x) * b);
		ans = max(ans, (b - 1 - y) * a);
		ans = max(ans, (y) * a);
		
		cout << ans << '\n';
	}

	return 0;
}
