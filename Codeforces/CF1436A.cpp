#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n, m;
	cin >> n >> m;

	int ai, sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		sum += ai;
	}

	return sum == m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}

	return 0;
}
