#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int t, n, k, c[N];
set<int> s[N];

int query(int l, int r) {
	int sz = 0;
	for (int i = l; i <= r; i++) {
		sz += c[i];
	}

	cout << "? " << sz;
	for (int i = l; i <= r; i++) {
		for (int x : s[i]) {
			cout << ' ' << x;
		}
	}
	cout << endl;

	int ans;
	cin >> ans;

	return ans;
}

int query(int idx) {
	int sz = n - c[idx];

	cout << "? " << sz;
	for (int i = 1; i <= n; i++) {
		if (s[idx].count(i)) continue;
		cout << ' ' << i;
	}
	cout << endl;

	int ans;
	cin >> ans;

	return ans;
}

void solve() {
	cin >> n >> k;
	
	for (int i = 1; i <= k; i++) {
		s[i].clear();

		cin >> c[i];

		int x;
		for (int j = 0; j < c[i]; j++) {
			cin >> x;
			s[i].insert(x);
		}
	}

	int l = 1;
	int r = k;

	cout << "? " << n;
	for (int i = 1; i <= n; i++) {
		cout << ' ' << i;
	}
	cout << endl;

	int mx;
	cin >> mx;

	int q;
	while (l < r) {
		int m = (l + r) / 2;
		int q = query(l, m);

		if (q == mx) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	int smx = query(l);
	
	cout << '!';
	for (int i = 1; i <= k; i++) {
		if (i == l) {
			cout << ' ' << smx;
		}
		else {
			cout << ' ' << mx;
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	string good;
	while (t--) {
		solve();
		cin >> good;
		if (good == "Incorrect") {
			return 0;
		}
	}

	return 0;
}
