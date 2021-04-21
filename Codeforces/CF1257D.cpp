#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, m, a[N], mxp[N];

int solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> m;

	int s, p;
	for (int i = 0; i < m; i++) {
		cin >> p >> s;
		mxp[s] = max(mxp[s], p);
	}
	for (int i = n - 1; i > 0; i--) {
		mxp[i] = max(mxp[i + 1], mxp[i]);
	}

	int md = 0;
	int cnt = 0;
	while (md < n) {
		cnt += 1;

		int mtd = 0;
		int mxatk = a[md + mtd];

		while (md + mtd < n && mxp[mtd + 1] >= mxatk) {
			mtd += 1;
			mxatk = max(mxatk, a[md + mtd]);
		}

		if (mtd == 0) {
			return -1;
		}

		md += mtd;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		for (int i = 0; i <= n + 10; i++) {
			mxp[i] = 0;
		}
		cout << solve() << '\n';
	}

	return 0;
}
