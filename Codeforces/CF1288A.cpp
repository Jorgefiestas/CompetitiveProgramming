#include <bits/stdc++.h>
using namespace std;
int t, n, d;

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> d;

		bool poss = false;
		for (int x = 0; x * x <= d + 100; x++) {
			int temp = x + (x + d)/(x + 1);
			if (temp <= n) {
				poss = true;
				break;
			}
		}

		if (poss) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}
