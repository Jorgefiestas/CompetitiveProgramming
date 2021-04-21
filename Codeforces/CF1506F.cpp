#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int solve() {
	int n;
	cin >> n;

	vector<pii> points(n);

	for (int i = 0; i < n; i++) {
		cin >> points[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> points[i].second;
	}

	sort(points.begin(), points.end());

	int ans = 0;
	int cr = 1;
	int cc = 1;

	for (auto [r, c] : points) {
		int dr = r - cr;
		int dc = c - cc;

		if ((cr + cc) % 2) {
			ans += (dr - dc + 1) / 2;
		}
		else {
			if (dr == dc) ans += dr;
			else ans += (dr - dc) / 2;
		}

		cr = r;
		cc = c;
	}

	return ans;
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
