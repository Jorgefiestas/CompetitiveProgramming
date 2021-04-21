#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
int t, n;
long long x;

long long solve() {
	cin >> n >> x;

	vector<pii> a;

	for (int i = 1; i <= n; i++) {
		int ai;
		cin >> ai;
		a.push_back({ai, 1});
	}

	for (int i = 0; i < a.size(); i++) {
		auto [v, cnt] = a[i];

		if (v % x) break;

		a.push_back({v / x, cnt * x});
	}

	long long ans = 0;
	for (auto [v, cnt] : a) {
		ans += v * cnt;
	}

	return ans;
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
