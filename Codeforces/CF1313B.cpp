#include <bits/stdc++.h>
using namespace std;
int t, n, x, y;

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> x >> y;

		if (x < y) {
			swap(x, y);
		}

		int mn = max(1, min(n, x + y - n + 1));
		int mx = min(n, x + y - 1);
		
		cout << mn << ' ' << mx << endl;
	}

	return 0;
}
