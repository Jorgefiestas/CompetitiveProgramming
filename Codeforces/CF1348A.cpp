#include <bits/stdc++.h>
using namespace std;
int t, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t; 

	while (t--) {
		cin >> n;

		int lft = 0;
		int rght = 0;
		for (int i = 1; i < n / 2; i++) {
			lft += (1 << i);
		}
		lft += (1 << n);

		for (int i = n / 2; i < n; i++) {
			rght += (1 << i);
		}

		cout << abs(lft - rght) << '\n';
	}

	return 0;
}
