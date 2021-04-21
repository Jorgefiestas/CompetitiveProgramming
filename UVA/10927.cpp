#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pii = pair<int, int>;
const int N = 100000;
int n;
map<pii, int> height;

struct pt {
	int x, y, z;

	ld sq() const {
		return (ld) x * x + (ld) y * y;
	}
	ld abs() const {
		return sqrtl(sq());
	}
	bool operator<(const pt &p) const {
		return abs() < p.abs();
	}
};

pt p[N];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
	}

	sort(p, p + n);

	vector<pii> ans;
	for (int i = 0; i < n; i++) {
		int g = gcd(abs(p[i].x), abs(p[i].y));
		pii vec = {p[i].x / g, p[i].y / g};

		if (!height.count(vec)) {
			height[vec] = p[i].z;
			continue;
		}

		if (height[vec] < p[i].z) {
			height[vec] = p[i].z;
		}
		else {
			ans.push_back({p[i].x, p[i].y});
		}
	}

	sort(ans.begin(), ans.end());

	if (ans.empty()) {
		cout << "All the lights are visible.\n";
	}
	else {
		cout << "Some lights are not visible:\n";
		for (int i = 0; i < ans.size(); i++) {
			char col = (i == ans.size() - 1) ? '.' : ';';
			cout << "x = " << ans[i].first << ", ";
			cout << "y = " << ans[i].second << col << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int ti = 1;
	while (cin >> n, n) {
		height.clear();
		cout << "Data set " << ti << ":\n";
		solve();
		ti += 1;
	}

	return 0;
}
