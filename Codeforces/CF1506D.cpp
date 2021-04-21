#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n;
	cin >> n;

	map<int, int> cnt;

	int ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		cnt[ai] += 1;
	}

	multiset<int> sz;
	for (auto [x, c] : cnt) {
		sz.insert(c);
	}

	while (sz.size() > 1) {
		int mn = *sz.begin();
		sz.erase(sz.begin());

		for (int i = 0; i < mn; i++) {
			int mx = *prev(sz.end());
			sz.erase(prev(sz.end()));
			mx -= 1;
			sz.insert(mx);
		}
	}

	return *sz.begin();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
