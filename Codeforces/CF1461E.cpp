#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long k, l, r, t, x, y;
bool seen[N];

int yes() {
	cout << "Yes\n";
	return 0;
}

int no() {
	cout << "No\n";
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> l >> r >> t >> x >> y;

	if (x > y) {
		long long days = 0;

		if (k + y > r)  {
			k -= x;
			days += 1;
		}

		if (k < l) return no();

		long long nx;
		nx = x - y;

		days += (k - l) / nx;

		if (days >= t) {
			return yes();
		}
		return no();
	}

	r -=l;
	k -= l;

	if (k < 0 || k > r) {
		return no();
	}

	long long days = 0;

	while (true) {
		days += k / x;

		if (seen[k % x]) {
			return yes();
		}
		seen[k % x] = true;

		k = y + k % x;
		if (k < 0 || k > r) break;
		
	}

	if (days >= t) {
		return yes();
	}

	return no();
}
