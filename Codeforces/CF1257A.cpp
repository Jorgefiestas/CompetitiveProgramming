#include <bits/stdc++.h>
using namespace std;
int t, n, x, a, b;

int solve() {
	cin >> n >> x >> a >> b;

	if (a > b) {
		swap(a, b);
	}

	return min(b - a + x, n - 1);
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
