#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> q(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	}

	set<int> st;
	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q[i] != q[i - 1]) {
			cout << q[i] << ' ';
			st.erase(q[i]);
		}
		else  {
			cout << *st.begin() << ' ';
			st.erase(st.begin());
		}
	}
	cout << '\n';

	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q[i] != q[i - 1]) {
			cout << q[i] << ' ';
			st.erase(q[i]);
		}
		else {
			auto it = prev(st.lower_bound(q[i]));
			cout << *it << ' ';
			st.erase(it);
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	while (t--) {
		solve();
	}

	return 0;
}
