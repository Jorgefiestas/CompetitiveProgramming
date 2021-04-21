#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 100;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int t, n, a[N];
map<char, int> toNum;

void solve() {
	cin >> n;

	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		a[i + 1] = toNum[c];
	}

	map<pii, int> recent;
	int l = -1;
	int r = 1e6;

	pii pos{0, 0};
	recent[pos] = 0;

	for (int i = 1; i <= n; i++) {
		pos.first += dx[a[i]];
		pos.second += dy[a[i]];

		if (recent.count(pos)) {
			int tr = i;
			int tl = recent[pos] + 1;
			if (tr - tl + 1 < r - l + 1) {
				r = tr;
				l = tl;
			}
		}
		recent[pos] = i;
	}

	if (l == -1) {
		cout << -1 << '\n';
		return;
	}
	cout << l << ' ' << r << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	toNum['L'] = 0;
	toNum['R'] = 1;
	toNum['U'] = 2;
	toNum['D'] = 3;

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
