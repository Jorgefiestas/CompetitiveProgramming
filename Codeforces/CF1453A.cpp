#include <bits/stdc++.h>
using namespace std;
int t, n, m;

int solve() {
	cin >> n >> m;

	set<int> seen;

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		seen.insert(ai);
	}
	for (int i = 1; i <= m; i++) {
		cin >> ai;
		seen.insert(ai);
	}

	return n + m - seen.size();
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
