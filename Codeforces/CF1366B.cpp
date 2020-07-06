#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;

int solve() {
	cin >> n >> x >> m;

	int l = x;
	int r = x;

	int li, ri;
	for (int i = 0; i < m; i++) {
		cin >> li >> ri;

		if (li <= l && l <= ri) {
			l = min(l, li);
		}
		if (li <= r && r <= ri) {
			r = max(r, ri);
		}
	}

	return (r - l + 1);

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
