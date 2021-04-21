#include <bits/stdc++.h>
using namespace std;
int q;
long long n;

long long mx_edgs(long long x) {
	return (long long) x * (x - 1) / 2;
}

long long query() {
	cin >> n;

	long long l = 0;
	long long r = n;

	long long k = -1;
	while (l <= r) {
		long long m = (l + r) / 2;

		if ((long long) m < mx_edgs(n - m)) {
			k = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	long long can1 = 2 * k;
	long long can2 = k + 1 + mx_edgs(n - k - 1);
	return max(can1, can2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;

	for (int qi = 0; qi < q; qi++) {
		cout << query() << '\n';
	}

	return 0;
}
