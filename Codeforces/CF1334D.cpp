#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
long long l, r;

void solve() { 
	cin >> n >> l >> r;

	int b = 1;
	long long bsum  = 0;
	while (b < n && bsum + 1LL * (2 * (n - b)) < l) {
		bsum += 1LL * 2 * (n - b);
		b++;
	}

	int a = 1;
	a = b + (l - bsum + 1) / 2;

	if (b == n) {
		b = 1;
	}

	for (long long i = l; i <= r; i++) {
		if (i % 2) {
			cout << b << ' ';
			i++;
		}

		if (i > r) break;

		cout << a << ' ';

		a++;
		if (a == n + 1) {
			b++;
			a = b + 1;
		}
		if (b == n)  {
			b = 1;
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
