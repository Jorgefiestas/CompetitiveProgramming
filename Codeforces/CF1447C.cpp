#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int L = 60;
int t, n, cnt[L];
long long k;

void solve() {
	cin >> n >> k;

	vector<pii> w;

	int wi;
	for (int i = 1; i <= n; i++) {
		cin >> wi;
		if (wi <= k) {
			w.push_back({wi, i});
		}
	}

	sort(w.begin(), w.end(), greater<pii>());

	vector<int> ans;
	long long sum = 0;

	for (auto [wi, i] : w) {
		sum += (long long) wi;
		ans.emplace_back(i);

		if (sum >= (k + 1) / 2) {
			break;
		}
	}

	if (sum < (k + 1) / 2) {
		cout << -1 << '\n';
		return;
	}

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
