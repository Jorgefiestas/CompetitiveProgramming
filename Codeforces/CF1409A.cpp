#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int solve() {
	cin >> a >> b;

	int d = abs(a - b);
	return (d + 9) / 10;
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
