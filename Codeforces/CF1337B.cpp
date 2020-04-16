#include <bits/stdc++.h>
using namespace std;
int t, h, n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> h >> n >> m;

		while (n && h > 19) {
			h = h / 2 + 10;
			n--;
		}
		
		if (h <= 10 * m) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
