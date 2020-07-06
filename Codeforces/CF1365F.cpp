#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 505;
int t, n, mid, a[N], b[N];

bool solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	mid = (n % 2) ? n / 2 + 1 : n / 2;

	if (n % 2 && a[n / 2 + 1] != b[n / 2 + 1]) {
		return false;
	}

	multiset<pii> pairs;
	for (int i = 1; i <= n / 2; i++) {
		pairs.insert({a[i], a[n - i + 1]});
	}

	for (int l = 1; l <= n / 2; l++) {
		if (!pairs.count({b[l], b[n - l + 1]})) {
			swap(b[l], b[n - l  + 1]);
		}
		if (!pairs.count({b[l], b[n - l + 1]})) {
			return false;
		}

		auto it = pairs.find({b[l], b[n - l + 1]});
		pairs.erase(it);
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
