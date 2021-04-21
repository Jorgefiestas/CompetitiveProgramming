#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int L = 32;
int t, n, cnt[L];

int solve() {
	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;

		for (int b = 0; b < L; b++) {
			cnt[b] += !!(x & (1 << b));
		}
	}

	for (int b = L - 1; b >= 0; b--) {
		if (cnt[b] % 2 == 0) continue;
		if ((cnt[b] - 1) % 4 == 0) {
			return 2;
		}

		bool z = (n - cnt[b]) % 2;
		return z ? 2 : 0;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	string print[] = {"LOSE", "DRAW", "WIN"};

	while (t--) {
		memset(cnt, 0, sizeof cnt);

		int ans = solve();
		cout << print[ans] << '\n';
	}

	return 0;
}
