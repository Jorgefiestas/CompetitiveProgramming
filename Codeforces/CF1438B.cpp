#include <bits/stdc++.h>
using namespace std;
int t, n;

bool solve() {
	cin >> n;

	set<int> seen;

	bool poss = false;

	int bi;
	for (int i = 1; i <= n; i++) {
		cin >> bi;
		if (seen.count(bi)) {
			poss = true;
		}
		seen.insert(bi);
	}

	return poss;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
