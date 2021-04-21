#include <bits/stdc++.h>
using namespace std;
int t, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		int q = n / 2020;
		int r = n % 2020;

		cout << (q >= r ? "YES" : "NO") << '\n';
	}

	return 0;
}
