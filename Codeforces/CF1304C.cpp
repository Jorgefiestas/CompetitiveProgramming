#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int q, n, m;
int l[N], h[N];
pair<int, int> t[N];

bool solve() {
	cin >> n >> m;
	int ct = 0;
	int ch = m;
	int cl = m;

	for (int i = 0; i < n; i++) {
		cin >> t[i].first >> l[i] >> h[i];
		t[i].second = i;
	}
	sort(t, t + n);

	for (int i = 0; i < n; i ++) {
		int ti = t[i].first;
		int li = l[t[i].second];
		int hi = h[t[i].second];

		int dt = ti - ct;

		if (ch < li) {
			if (ch + dt < li) {
				return false;
			}

			ch = min(ch + dt, hi);
			cl = li;
		}
		else if (cl > hi) {
			if (cl - dt > hi) {
				return false;
			}

			cl = max(cl - dt, li);
			ch = hi;
		}
		else {
			cl = max(cl - dt, li);
			ch = min(ch + dt, hi);
		}

			ct = ti;
	}

		return true;
}


	int main() {
		ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;

	while (q--) {
		if (solve()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
