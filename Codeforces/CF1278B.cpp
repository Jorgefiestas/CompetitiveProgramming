#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int solve() {
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}

	int dif = b - a;

	int op = 0;
	while (op * (op + 1) / 2 < dif || ((op + 1) * op / 2 - dif) % 2) {
		op += 1;
	}

	return op;
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
