#include <bits/stdc++.h>
using namespace std;
int t, k;
bool a[8];

int solve() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	
	int ans = 0;
	int week = 0;
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
		week += a[i];
	}

	int weeks = (k + week - 1) / week;
	if (weeks > 2) {
		ans += (weeks - 2) * 7;
		k -= (weeks - 2) * week;
	}

	int best = INT_MAX;
	for (int i = 0; i < 7; i++) {
		int j = 0;
		int cnt = 0;
		
		while (cnt < k) {
			cnt += a[(i + j) % 7];
			j += 1;
		}

		best = min(best, j);
	}

	return ans + best;
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
