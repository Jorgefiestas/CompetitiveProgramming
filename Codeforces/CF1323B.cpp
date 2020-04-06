#include <bits/stdc++.h>
using namespace std;
int n[2], k;
vector<int> cnt[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n[0] >> n[1] >> k;

	int x;
	for (int r = 0; r < 2; r++) {
		int ones = 0;
		for (int i = 0; i < n[r]; i++) {
			cin >> x;
			if (x) {
				ones++;
			}
			else {
				cnt[r].emplace_back(ones);
				ones = 0;
			}
		}
		if (ones) {
			cnt[r].emplace_back(ones);
		}
	}

	long long ans = 0;
	for (int i = 1; i * i <= k; i++) {
		if (k % i) continue;

		int a[] = {i, k / i};
		for (int j = 0; j < 2; j++) {
			int ways[2] = {0, 0}; 
			for (int r = 0; r < 2; r++) {
				for (int len : cnt[r]) {
					if (len < a[r]) continue;
					ways[r] += (len - a[r] + 1);
				}
			}
			ans += ways[0] * 1LL * ways[1];
			swap(a[0], a[1]);
			if (i * i == k) break;
		}
	}

	cout << ans << '\n';
	return 0;
}
