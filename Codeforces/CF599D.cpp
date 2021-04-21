#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const long long N = 1442250;
long long x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x;

	vector<pll> ans;

	for (long long n = 1; n < N; n++) {
		long long num = 6 * x - n * (n + 1) * (2 * n + 1);
		long long den = n * (n + 1) * 3;

		if (num < 0) break;
		if (num % den) continue;

		long long d = num / den;
		ans.push_back({n, n + d});
	}

	int half = (int) ans.size() - 1;
	if (ans[half].first == ans[half].second) half--;

	for (int i = half; i >= 0; i--) {
		ans.push_back({ans[i].second, ans[i].first});
	}

	cout << ans.size() << '\n';
	for (auto [n, m] : ans) {
		cout << n << ' ' << m << endl;
	}

	return 0;
}
