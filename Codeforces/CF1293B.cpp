#include <bits/stdc++.h>
using namespace std;
using ld = long double;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	ld ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (ld) 1 / i;
	}

	cout << fixed;
	cout << setprecision(9);

	cout << ans << '\n';

	return 0;
}
