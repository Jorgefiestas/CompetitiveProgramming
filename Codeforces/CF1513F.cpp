#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
int n, a[N], b[N];

int findMin(const vector<pii> &ab, const vector<pii> &ba) {
	int da = 0;
	set<int> seen;

	int j = 0;
	for (auto [ai, bi] : ab) { 
		while (j < ba.size() && ba[j].first <= ai) {
			seen.insert(ba[j].second);
			j += 1;
		}

		auto it = seen.upper_bound(bi);
		auto jt = seen.lower_bound(bi);

		if (jt != seen.end()) {
			da = min(da, 2 * ai - 2 * bi);
		}

		if (it == seen.begin()) continue;

		int x = *prev(it);
		if (x >= ai) 
			da = min(da, 2 * ai - 2 * x);
	}

	return da;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	long long sum = 0;

	vector<pii> ab, ba;
	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) ab.push_back({a[i], b[i]});
		if (a[i] > b[i]) ba.push_back({b[i], a[i]});
		sum += (long long) abs(a[i] - b[i]);
	}

	sort(ab.begin(), ab.end());
	sort(ba.begin(), ba.end());

	int mn = min(findMin(ab, ba), findMin(ba, ab));
	cout << sum + 1LL * mn << '\n';

	return 0;
}
