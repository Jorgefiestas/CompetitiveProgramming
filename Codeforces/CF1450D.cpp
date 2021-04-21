#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int t, n, a[N], cnt[N];

void solve() {
	cin >> n;

	bool perm = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] += 1;

		if (cnt[a[i]] > 1)
			perm = false;
	}

	int l = 1;
	int r = n;

	bool bad = false;
	string ans;

	for (int i = 1; i < n; i++) {
		if (!cnt[i])
			bad = true;

		if (bad) {
			ans += '0';
			continue;
		}

		ans += '1';

		if (a[l] != i && a[r] != i) {
			bad = true;
		}
		else if (a[l] == i) {
			l += 1;
		}
		else if (a[r] == i) {
			r -= 1;
		}

		bad = bad || cnt[i] > 1;
	}

	if (perm) 
		ans += '1';
	else 
		ans += '0';

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		for (int i = 1; i <= n; i++)
			cnt[i] = 0;

		solve();
	}

	return 0;
}
