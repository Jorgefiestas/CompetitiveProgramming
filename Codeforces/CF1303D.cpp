#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int t, m, ans;
long long n, a[N];
map<int, int> cnt;

bool split_nearest(int idx) {
	auto p = cnt.upper_bound(idx);

	if (p == cnt.end()) {
		return false;
	}

	for (int i = (*p).first; i > idx; i--) {
		cnt[i]--;
		cnt[i - 1] += 2;
		ans++;
	}

	return true;
}

void solve() {
	cin >> n >> m;

	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cnt[31 - __builtin_clz(x)]++;
	}

	for (int i = 0; i < 63; i++) {
		if (n & (1LL << i)) {
			if (!cnt[i]) {
				if (!split_nearest(i)) {
					cout << -1 << '\n';
					return;
				}
			}
			cnt[i]--;
		}
		cnt[i + 1] += cnt[i] / 2;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	while(t--) {
		cnt.clear();
		ans = 0;
		solve();
	}

	return 0;
}
