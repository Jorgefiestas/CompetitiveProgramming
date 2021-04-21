#include <bits/stdc++.h>
using namespace std;
long long n, k;

bool query(long long l, long long r) {
	string ans;

	cout << l << ' ' << r << endl;
	cin >> ans;

	return ans[0] == 'Y';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<long long> dist(0, min(n - 1, 44LL));

	long long l = 1;
	long long r = n;
	string q;

	while (l <= r) {
		if (r - l  <= 45) {
			long long idx = dist(gen);

			if (query(l + idx, l + idx)) {
				return 0;
			}

			l = max(1LL, l - k);
			r = min(n, r + k);
			continue;
		}

		long long m = (l + r) / 2;
		if (query(l, m)) {
			l = max(1LL, l - k);
			r = min(n, m + k);
		}
		else {
			l = max(1LL, m - k);
			r = min(n, r + k);
		}
	}

	return 0;
}
