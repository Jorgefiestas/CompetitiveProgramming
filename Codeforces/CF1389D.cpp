#include <bits/stdc++.h>
using namespace std;
int t;
long long n, k, l1, r1, l2, r2;

long long solve() {
	cin >> n >> k;
	cin >> l1 >> r1;
	cin >> l2 >> r2;
	

	if (l1 <= r2 && l2 <= r1) {
		long long ovlp = max(min(r1, r2) - max(l1, l2), 0LL);
		long long w = max(r1, r2) - min(l1, l2) - ovlp;

		long long il = ovlp * n;	
		if (il >= k) {
			return 0;
		}

		if (il + n * w >= k) {
			return k - il;
		}

		il += w * n;
		return w * n + (k - il) * 2LL;
	}

	long long d = max(l1 - r2, l2 - r1);
	long long il = max(r1, r2) - min(l1, l2);
	
	if (il >= k) {
		return d + k;
	}

	long long op = d + il;

	for (int i = 1; i < n; i++) {
		long long tsize = max(r1, r2) - min(l1, l2);
		if (il + tsize >= k) {
			tsize = k - il;
		}

		long long op1 = d + tsize;
		long long op2 = 2LL * tsize;

		op += min(op1, op2);
		il += tsize;

		if (il >= k) {
			return op;
		}
	}

	return op + (k - il) * 2LL;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
