#include <bits/stdc++.h>
using namespace std;
int t, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		int x;
		vector<int> cnt[2];
		for (int i = 0; i < n; i++) {
			cin >> x;
			cnt[x % 2].emplace_back(i + 1);
		}

		if (!cnt[0].empty()) {
			cout << "1\n";
			cout << cnt[0][0] << '\n';
		}
		else if (cnt[1].size() > 1) {
			cout << "2\n";
			cout << cnt[1][0] << ' ' << cnt[1][1] << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}
