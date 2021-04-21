#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int t, x, y;

pii solve() {
	cin >> x >> y;
	return {max(x - 1, 0), y};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		pii ans = solve();
		cout << ans.first << ' ' << ans.second << '\n';
	}

	return 0;
}
