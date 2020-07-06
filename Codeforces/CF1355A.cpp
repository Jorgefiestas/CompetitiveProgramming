#include <bits/stdc++.h>
using namespace std;
int t;
long long a1, k;

long long score(long long x) {
	long long mx = 0;
	long long mn = 9;
	while (x) {
		mx = max(mx, x % 10);
		mn = min(mn, x % 10);
		x /= 10;
	}

	return mx * mn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> a1 >> k;

		long long s = 1;
		for (long long i = 1; s && i < k; i++) {
			s = score(a1);
			a1 += s;
		}

		cout << a1 << '\n';
	}

	return 0;
}
