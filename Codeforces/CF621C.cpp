#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 1e5 + 100;
int n, p, l[N], r[N];

int cnt(int i) {
	return r[i] - l[i] + 1 - r[i] / p + (l[i] - 1) / p;
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;

	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}

	ld ev = 0;
	for (int i = 1; i < n; i++) {
		int cnt1 = cnt(i);
		int cnt2 = cnt(i + 1);

		ld p1 = (ld) cnt1 / (r[i] - l[i] + 1);
		ld p2 = (ld) cnt2 / (r[i + 1] - l[i + 1] + 1);

		ev += (ld) (1.0 - p1 * p2) * 1000.0;
	}
	int cnt1 = cnt(n);
	int cnt2 = cnt(1);

	ld p1 = (ld) cnt1 / (r[n] - l[n] + 1);
	ld p2 = (ld) cnt2 / (r[1] - l[1] + 1);
	ev += (ld) (1.0 - p1 * p2) * 1000.0;

	cout << fixed << setprecision(15) << (ld) 2.0 * ev << '\n';

	return 0;
}
