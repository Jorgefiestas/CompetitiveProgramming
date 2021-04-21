#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n;

int mex(set<int> &s) {
	int prev = -1;
	for (int x : s) {
		if (x != prev + 1) break;
		prev += 1;
	}
	return prev + 1;
}

int solve() {
	cin >> n;

	set<int> a, b;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (!a.count(x)) {
			a.insert(x);
		}
		else {
			b.insert(x);
		}
	}

	return mex(a) + mex(b);
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
