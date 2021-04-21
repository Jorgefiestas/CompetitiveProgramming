#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int SA = 40005;
int n, cnt[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> cnt[i];
	}

	long long ans = LLONG_MAX;

	for (int s = 1; s < SA; s++) {
		long long can = 0;
		bool good = true;
		for (int i = 0; i < n; i++) {
			int k = cnt[i] / s;
			int rem = cnt[i] % s;
			can += k + !!rem;

			if (rem && k < s - 1 - rem) {
				good = false;
				break;
			}
		}

		if (good) {
			ans = min(ans, can);
		}
	}

	for (int k = 1; k < SA; k++) {
		long long can = 0;

		int s = cnt[0] / k + 1;
		if (s == 0) {
			break;
		}

		bool good = true;

		for (int i = 0; i < n; i++) {
			int tk = cnt[i] / s;
			int rem = cnt[i] % s;
			can += tk + !!rem;

			if (rem && tk < s - 1 - rem) {
				good = false;
				break;
			}
		}

		if (good) {
			ans = min(ans, can);
		}

		if (cnt[0] % k) continue;

		s = cnt[0] / k;
		can = 0;
		good = true;

		for (int i = 0; i < n; i++) {
			int tk = cnt[i] / s;
			int rem = cnt[i] % s;
			can += tk + !!rem;

			if (rem && tk < s - 1 - rem) {
				good = false;
				break;
			}
		}

		if (good) {
			ans = min(ans, can);
		}
	}

	cout << ans << '\n';

	return 0;
}
