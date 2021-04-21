#include <bits/stdc++.h>
using namespace std;
using ld = long double;

ld solve() {
	int n;
	cin >> n;

	vector<ld> miners, mines;

	int x, y;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> x >> y;
		if (x == 0) miners.push_back(abs(y));
		else mines.push_back(abs(x));
	}

	sort(miners.begin(), miners.end());
	sort(mines.begin(), mines.end());

	ld ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sqrt(miners[i] * miners[i] + mines[i] * mines[i]);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	cout << fixed << setprecision(15);

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
