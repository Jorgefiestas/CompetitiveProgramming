#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, q, ft[N];

void update(int idx, int v) {
	while (idx < N) {
		ft[idx] += v;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += ft[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int kth(int k) {
	int l = 1;
	int r = n;

	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int cnt = query(m);
		if (cnt >= k) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;

	int ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		update(ai, 1);
	}

	int k;
	for (int i = 0; i < q; i++) {
		cin >> k;

		if (k < 0) {
			k = -k;
			int rem = kth(k);
			update(rem, -1);
		}
		else {
			update(k, 1);
		}
	}

	int f = kth(1);
	cout << f << '\n';

	return 0;
}
