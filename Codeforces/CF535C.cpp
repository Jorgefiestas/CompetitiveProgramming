#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a, b, n;

long long sum(int l, int r) {
	long long k = (long long) (r - l + 1) * a;
	long long v = (long long) (l + r) * (r - l + 1) / 2LL;
	return (long long) k + b * 1LL * v;
}

long long f(int x) {
	return (long long) a + b * 1LL * x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> n;
int li, ti, mi;
	for (int i = 0; i < n; i++) {
		cin >> li >> ti >> mi;

		long long k = (long long) mi * ti;

		int sol = -1;
		int l = li - 1;
		int r = max(1, li - 1);

		while (f(r) <= ti && sum(l, r) <= k) {
			sol = r;
			r <<= 1;
			l++;
		}

		while (l <= r) {
			int m = (l + r) / 2;
			if (f(m) <= (long long) ti && sum(li - 1, m) <= k) {
				sol = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}

		if (sol >= 0) {
			sol++;
		}

		cout << sol << '\n';
	}

	return 0;
}
