#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
long long c, hr, hb, wr, wb;

long long cnt(long long x, long long y) {
	return x * hr + y * hb;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> hr >> hb >> wr >> wb;

	long long ans = 0;

	for (long long i = 0; i < N; i++) {
		if (i * wr > c) break;
		long long cb = (c - i * wr) / wb;
		ans = max(ans, cnt(i, cb));
	}

	for (long long i = 0; i < N; i++) {
		if (i * wb > c) break;
		long long cr = (c - i * wb) / wr;
		ans = max(ans, cnt(cr, i));
	}

	long long mxr = c / wr;
	long long mxb = c / wb;
	
	for (int i = 0; i < N; i++) {
		if (i > mxr) break;
		long long cr = mxr - i;
		long long cb = (c - cr * wr) / wb;
		ans = max(ans, cnt(cr, cb));
	}

	for (int i = 0; i < N; i++) {
		if (i > mxb) break;
		long long cb = mxb - i;
		long long cr = (c - cb * wb) / wr;
		ans = max(ans, cnt(cr, cb));
	}

	cout << ans << '\n';

	return 0;
}
