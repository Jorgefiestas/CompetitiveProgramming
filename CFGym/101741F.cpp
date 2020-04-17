#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k;
long long a[N];

long long gcd(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	long long ans = 1;
	for (int tries = 0; tries < 100 < n; tries++) {
		random_shuffle(a, a + n);
		long long g = 0;
		int  cnt = k;
		for (int i =  0; i < n; i++) {
			long long tg = gcd(g, a[i]);
			if (tg <= ans) {
				if (!cnt) {
					g = 1;
					break;
				}
				cnt--;
			}
			else {
				g = tg;
			}
		}
		ans = max(ans, g);
	}

	cout << ans << '\n';

	return 0;
}
