#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, h[N], w[N];

struct Friend {
	int x, y, idx;

	bool operator <(const Friend &f) const {
		if (x == f.x)
			return y < f.y;
		return x < f.x;
	}
};

struct MonoSet {
	set<Friend> st;

	MonoSet() {
		st.insert({INT_MAX, INT_MIN, -1});
	}

	void add(int x, int y, int i) {
		auto it = st.upper_bound({x, y, i});

		if (it != st.begin() && prev(it)->y <= y)
			return;

		it = st.insert({x, y, i}).first;
		while (it->y <= next(it)->y) {
			st.erase(next(it));
		}
	}

	int query(int x, int y) {
		auto it = st.lower_bound({x, 0, -1});

		if (it == st.begin() || prev(it)->y >= y)
			return -1;
		return prev(it)->idx;
	}
};

void solve() {
	cin >> n;

	MonoSet st;

	for (int i = 1; i <= n; i++) {
		cin >> h[i] >> w[i];

		st.add(h[i], w[i], i);
		st.add(w[i], h[i], i);
	}

	for (int i = 1; i <= n; i++) {
		int c1 = st.query(h[i], w[i]);
		int c2 = st.query(w[i], h[i]);
		cout << max(c1, c2) << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
