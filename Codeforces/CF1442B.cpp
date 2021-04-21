#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
int t, n, k, a[N], b[N], pos[N];

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	a[n + 1] = 0;

	set<int> toAdd;
	toAdd.insert(0);

	for (int i = 1; i <= k; i++) {
		cin >> b[i];
		toAdd.insert(b[i]);
	}

	int ans = 1;

	for (int i = 1; i <= k; i++) {
		int idx = pos[b[i]];
		toAdd.erase(b[i]);

		int rgt = a[idx - 1];
		int lft = a[idx + 1];

		int cnt = 0;
		if (!toAdd.count(rgt)) {
			cnt += 1;
		}
		if (!toAdd.count(lft)) {
			cnt += 1;
		}
		ans = mul(ans, cnt);

	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
