#include <bits/stdc++.h>
using namespace std;
int t;

int solve() {
	int n;
	cin >> n;

	int cnt[3] = {0, 0, 0};

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		cnt[ai % 3] += 1;
	}

	int ans = 0;
	for (int it = 0; it < 2; it++) {
		for (int i = 0; i < 3; i++) {
			if (cnt[i] < n / 3) continue;

			int j = (i + 1) % 3;
			cnt[j] += cnt[i] - n / 3;
			ans += cnt[i] - n / 3;
			cnt[i] = n / 3;
		}
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
