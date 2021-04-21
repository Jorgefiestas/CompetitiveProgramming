#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, cnt[N];
bitset<N> dp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	dp[0] = true;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		dp = dp | (dp << x);
	}

	cnt[0] = 1;
	for (int i = 1; i < N; i++) {
		cnt[i] = cnt[i - 1] + !!dp[i];
	}

	int l, r;
	for (int qi = 0; qi < q; qi++) {
		cin >> l >> r;
		cout << cnt[r] - cnt[l - 1] << '\n';
	}

	return 0;
}
