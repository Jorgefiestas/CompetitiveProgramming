#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve() {
	int n;
	cin >> n;

	vector<pii> vec;

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		vec.push_back({ai, i});
	}

	sort(vec.begin(), vec.end());

	vector<int> ans;

	long long sum = 0;
	for (auto [v, i] : vec) {
		if (v > sum) {
			ans.clear();
		}

		ans.push_back(i);
		sum += (long long) v;
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
