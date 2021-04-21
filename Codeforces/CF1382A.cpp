#include <bits/stdc++.h>
using namespace std;
int t, n, m;

void solve() {
	cin >> n >> m;

	set<int> st;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		st.insert(x);
	}

	bool poss = false;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (st.count(x)) {
			ans = x;
			poss = true;
		}
	}

	if (!poss) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	cout << 1 << ' ' << ans << '\n';

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
