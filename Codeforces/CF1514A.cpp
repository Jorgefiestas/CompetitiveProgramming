#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
set<int> squares;

bool solve() {
	int n;
	cin >> n;

	bool pos = false;

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		pos = pos || !squares.count(ai);
	}

	return pos;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		squares.insert(i * i);
	}

	int t;
	cin >> t;

	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}

	return 0;
}
