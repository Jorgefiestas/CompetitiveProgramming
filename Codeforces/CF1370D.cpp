#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, k, a[N];

int mnmx(int l, int r, int mx) {
	int cnt = 0;
	bool ava = true;
	for (int i = l; i <= r; i++) {
		if (!ava || a[i] > mx) {
			ava = true;
			continue;
		}
		cnt++;
		ava = false;
	}

	return cnt;
}

int bs(int li, int ri, int ki) {
	int l = 1;
	int r = 1e9;

	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		int cnt = mnmx(li, ri, m);

		if (cnt >= ki) {
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

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans;
	if (k % 2) {
		ans = min(bs(0, n - 1, k / 2 + 1), bs(1, n - 2, k / 2));
	}
	else {
		ans = min(bs(0, n - 2, k / 2), bs(1, n - 1, k / 2));
	}

	cout << ans << '\n';

	return 0;
}
