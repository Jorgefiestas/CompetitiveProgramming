#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int t, n, x, a[N];

bool is_sorted(int s, int e) {
	for (int i = s + 1; i <= e; i++) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}

int solve() {
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int cnt = 0;
	for (int i = 2; i <= n ; i++) {
		if (a[i] >= a[i - 1]) continue;

		for (int j = 1; j < n; j++) {
			if (a[j] <= x) continue;

			swap(a[j], x);
			cnt += 1;
			if (is_sorted(1, i)) {
				break;
			}
		}

		if (!is_sorted(1, i)) {
			return -1;
		}
	}

	return cnt;
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
