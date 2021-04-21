#include <bits/stdc++.h>
using namespace std;
int t, n;

int solve() {
	cin >> n;
	int rt = sqrt(2 * n - 1);
	return (rt + 1) / 2 - 1;
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
