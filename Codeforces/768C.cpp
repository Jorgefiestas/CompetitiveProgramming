#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int X = 2e3 + 5;
int n, k, x;
int cnt[X];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> x;

	int ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		cnt[ai]++;
	}

	int temp[X];
	for (int i = 0; i < k; i++) {
		memset(temp, 0, sizeof temp);

		bool added = 0;
		for (int j = 0; j < X; j++) {
			if (!cnt[j]) continue;
			if (cnt[j] % 2) {
				temp[j ^ x] += cnt[j] / 2 + (added ? 0 : 1);
				temp[j] += cnt[j] / 2 + (added ? 1 : 0);
				added = !added;
			}
			else {
				temp[j ^ x] += cnt[j] / 2;
				temp[j] += cnt[j] / 2;
			}
		}

		for (int j = 0; j < X; j++) {
			cnt[j] = temp[j];
		}
	}

	int mn = INT_MAX, mx = -1;
	for (int i = 0; i < X; i++) {
		if (cnt[i]) {
			mx = max(mx, i);
			mn = min(mn, i);
		}
	}

	cout << mx << ' ' << mn << '\n';

	return 0;
}

