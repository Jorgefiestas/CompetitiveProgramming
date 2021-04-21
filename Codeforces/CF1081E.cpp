#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n;
long long x[N];

long long sqroot(long long x) {
	long long l = 1;
	long long r = 1e7;
	
	while (l <= r) {
		long long m = (l + r) / 2;
		if (m * m == x) {
			return m;
		}
		if (m * m < x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	long long y = 0;
	for (int i = 1; i <= n; i += 2) {
		cin >> x[i + 1];

		long long old = y * y;
		y += 1;
		while (y < 4e6 && sqroot(y * y + x[i + 1]) == -1) {
			y += 1;
		}

		if (y >= 4e6) {
			cout << "No\n";
			return 0;
		}

		x[i] = y * y - old;
		y = sqroot(y * y + x[i + 1]);
	}

	cout << "Yes\n";

	for (int i = 1; i <= n; i++) {
		cout << x[i] << ' ';
	}
	cout << '\n';

	return 0;
}
