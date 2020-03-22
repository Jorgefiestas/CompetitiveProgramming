#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100; 
int n;
long long h[N], c;

struct Sol {
	long long m = 0;
	long long k = 0;

	Sol() = default;
	Sol(long long _m, long long _k) {
		m = _m;
		k = _k;
	}

	long long eval(long long x) {
		return m * x + k;
	}

	double to(Sol &s) {
		if (m == s.m) {
			return LLONG_MAX;
		}
		return (double) (s.k - k) / (m - s.m);
	}
};

Sol dq[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	
	int l = 0, r = 0;
	long long opt = 0;
	for (int i = 2; i <= n; i++) {
		Sol nsol(-2 * h[i - 1], opt + c + h[i - 1] * h[i - 1]);

		while (r - l >= 2 && dq[r - 2].to(dq[r - 1]) >= dq[r - 2].to(nsol)) {
			r--;
		}
		dq[r++] = nsol;

		while (l + 1 < r && dq[l].eval(h[i]) >= dq[l + 1].eval(h[i])) {
			l++;
		}

		opt = dq[l].eval(h[i]) + h[i] * h[i];
	}

	cout << opt << '\n';

	return 0;
}
