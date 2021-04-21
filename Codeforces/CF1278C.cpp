#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 100;
int t, n, a[N], b[N];

int solve() { 
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	reverse(b, b + n);

	map<int, int> lft;

	int rem = 0;

	int score = 0;
	lft[0] = 0;
	for (int i = 0; i < n; i++) {
		score += (a[i] == 1) ? 1 : -1;
		lft[score] = i + 1;
		if (!score) {
			rem = i + 1;
		}
	}

	score = 0;
	for (int i = 0; i < n; i++) {
		score += (b[i] == 1) ? 1 : -1;
		if (!lft.count(-score)) continue;
		rem = max(rem, i + 1 + lft[-score]);
	}

	return 2 * n - rem;
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
