#include <bits/stdc++.h>
using namespace std;
int t, n, s, k;

int solve() {
	cin >> n >> s >> k;
	
	set<int> closed;

	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		closed.insert(x);
	}
	
	for (int i = 0; i < 1005; i++) {
		if (s + i <= n && !closed.count(s + i)) {
			return i;
		}
		if (s - i > 0 && !closed.count(s - i)) {
			return i;
		}
	}

	return 0;
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
