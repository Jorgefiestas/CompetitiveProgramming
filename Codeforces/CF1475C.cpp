#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

long long solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<pii> pairs(k);
	vector<int> cntb(n + 1, 0);
	vector<int> cntg(m + 1, 0);

	for (int i = 0; i < k; i++) {
		cin >> pairs[i].first;
		cntb[pairs[i].first]++;
	}
	for (int i = 0; i < k; i++) {
		cin >> pairs[i].second;
		cntg[pairs[i].second]++;
	}

	long long ans = 0;
	for (auto [ai, bi] : pairs) {
		int rem = cntb[ai] + cntg[bi] - 1;
		ans += (long long) (k - rem);
	}

	return ans / 2;
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
