#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, q, a[N];
long long dif[N];

long long a1, incSum, decSum;

void add(long long x) {
	if (x > 0) {
		incSum += (long long) x;
	}
	else {
		decSum += (long long) x;
	}
}

void rem(long long x) {
	if (x > 0) {
		incSum -= (long long) x;
	}
	else {
		decSum -= (long long) x;
	}
}

long long eval() {
	long long val = a1 + incSum;
	if (val <= 0) {
		return val / 2LL;
	}
	return (val + 1LL) / 2LL;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	a1 = a[1];

	for (int i = 2; i <= n; i++) {
		dif[i] = a[i] - a[i - 1];
		add(dif[i]);
	}

	cout << eval() << '\n';

	cin >> q;

	int l, r, x;
	for (int qi = 0; qi < q; qi++) {
		cin >> l >> r >> x;

		if (l == 1) {
			a1 += (long long) x;
		}
		else {
			rem(dif[l]);
			dif[l] += (long long) x;
			add(dif[l]);
		}

		if (r < n) {
			rem(dif[r + 1]);
			dif[r + 1] -= (long long) x;
			add(dif[r + 1]);
		}

		cout << eval() << '\n';
	}

	return 0;
}
