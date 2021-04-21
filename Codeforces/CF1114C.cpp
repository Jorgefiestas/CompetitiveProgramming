#include <bits/stdc++.h>
using namespace std;
long long n, b;
vector<long long> pd;
map<long long, long long> freq;
map<long long, long long> cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;

	for (long long d = 2; d * d <= b; d++) {
		if (b % d) continue;

		pd.emplace_back(d);
		while (b % d == 0) {
			freq[d] += 1;
			b /= d;
		}
	}
	if (b > 1) {
		pd.emplace_back(b);
		freq[b] += 1;
	}

	for (long long p : pd) {
		long long m = n;
		while (m) {
			cnt[p] += m / p;
			m /= p;
		}
	}

	long long ans = LLONG_MAX;
	for (auto p : cnt) {
		long long d = p.first;
		long long c = p.second;
		ans = min(ans, c / freq[d]);
	}

	cout << ans << '\n';

	return 0;
}
