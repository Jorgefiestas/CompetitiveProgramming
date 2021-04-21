#include <bits/stdc++.h>
using namespace std;
int t, p, h;

bool solve() {
	cin >> h >> p;

	while (p) {
		h -= p;
		p >>= 1;
	}

	return h <= 0;
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
