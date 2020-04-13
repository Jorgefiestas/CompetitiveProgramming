#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		int lp = 0, lc = 0;
		int pi,  ci;
		bool poss = true;
		for (int i = 0; i < n; i++) {
			cin >> pi >> ci;

			if(ci - lc > pi - lp) {
				poss = false;
			}
			if (lc > ci || lp > pi) {
				poss = false;
			}
			lc = ci;
			lp = pi;
		}

		if (poss) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
