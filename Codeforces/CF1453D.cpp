#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int t;
long long k, e[N];

void solve() {
	cin >> k;

	if (k & 1) {
		cout << -1 << '\n';
		return;
	}

	vector<bool> res;
	while (k) {
		int len = 1;
		while (e[len + 1] < k) {
			len += 1;
		}
		
		k -= e[len];
		res.push_back(1);
		for (int i = 1; i < len; i++) {
			res.push_back(0);
		}
	}

	cout << res.size() << '\n';
	for (bool b : res) {
		cout << b << ' ';
	}
	cout << '\n';
}
		

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 63; i++) {
		e[i] = 2 + 2 * e[i - 1];
	}

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
