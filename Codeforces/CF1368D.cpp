#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int B = 21;
int n, a[N];
int cnt[B];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];

		for (int b = 0; b < B; b++) {
			if (a[i] & (1 << b)) {
				cnt[b]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int b = 0; b < B; b++) {
			if (!cnt[b] && (a[i] & (1 << b))) {
				a[i] ^= (1 << b);
				continue;
			}
			if (cnt[b]) {
				a[i] |= (1 << b);
				cnt[b]--;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (long long) a[i] * a[i];
	}

	cout << ans << '\n';
	return 0;
}
