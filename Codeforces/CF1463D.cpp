#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int t, n, to[N];

int solve() {
	cin >> n;

	set<int> bs;
	vector<int> a(1);
	vector<int> b(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		bs.insert(b[i]);
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (bs.count(i)) continue;
		a.emplace_back(i);
	}

	for (int i = 1; i <= n; i++) {
		to[a[i]] = b[i];
	}

	int cnt = 1;
	int f = a[1];

	for (int x : a) {
		if (!x || x == f) continue;
		bool pdirf = to[f] > f;
		bool pdirx = to[x] > x;

		swap(to[f], to[x]);

		bool ndirf = to[f] > f;
		bool ndirx = to[x] > x;

		bool chngf = ndirf != pdirf;
		bool chngx = ndirx != pdirx;

		if (chngf != chngx) {
			cout << x << endl;
			cnt += 1;
		}
	}

	return cnt;
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
