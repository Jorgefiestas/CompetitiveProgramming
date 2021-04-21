#include <bits/stdc++.h>
using namespace std;

int mex(const set<int> &st) {
	int ans = 0;
	for (int x : st) {
		if (x != ans) break;
		ans++;
	}
	return ans;
}

int solve() {
	int n, k;
	cin >> n >> k;

	set<int> st;

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		st.insert(ai);
	}

	int mx = *prev(st.end());
	int nm = mex(st);
	int m = -1;

	while (k && nm != m && nm < mx) {
		m = nm;

		int x = (m + mx + 1) / 2;
		st.insert(x);

		k--;
		nm = mex(st);
	}

	int ans = st.size();

	if (nm > mx) {
		ans += k;
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
