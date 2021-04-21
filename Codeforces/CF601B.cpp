#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, q, a[N], d[N];
int lft[N], rgt[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			d[i] = abs(a[i] - a[i - 1]);
		}
	}
	d[0] = INT_MAX;
	d[n] = INT_MAX;

	stack<int> st;
	st.push(0);
	for (int i = 1; i < n; i++) {
		while (d[st.top()] <= d[i]) {
			st.pop();
		}
		lft[i] = st.top() + 1;
		st.push(i);
	}

	st = stack<int>();
	st.push(n);
	for (int i = n - 1; i > 0; i--) {
		while (d[st.top()] < d[i]) {
			st.pop();
		}
		rgt[i] = st.top() - 1;
		st.push(i);
	}

	int l, r;
	for (int qi = 0; qi < q; qi++) {
		cin >> l >> r;
		r -= 1;

		long long ans = 0;
		for (int i = l; i <= r; i++) {
			int lspan = i - max(l, lft[i]) + 1;
			int rspan = min(r, rgt[i]) - i + 1;
			ans += (long long) d[i] * lspan * rspan;
		}

		cout << ans << '\n';
	}

	return 0;
}
