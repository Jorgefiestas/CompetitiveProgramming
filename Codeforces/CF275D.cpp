#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, a[N];
bool sgn[N], swp[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long al = 0;
	for (int i = n; i >= 1; i--) {
		if (al - a[i] >= 0 && al - a[i] <= a[i]) {
			sgn[i] = 1;
			al -= a[i];
		}
		else {
			swp[i + 1] = 1;
			al = a[i] - al;
		}
	}

	for (int i = 1; i <= n; i++) {
		swp[i] = swp[i] ^ swp[i - 1];
		sgn[i] = sgn[i] ^ swp[i];
	}

	for (int i = 1; i <= n; i++) {
		char out = sgn[i] ? '-' : '+';
		cout << out;
	}
	cout << '\n';

	return 0;
}
