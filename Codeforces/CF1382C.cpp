#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;

void solve() {
	cin >> n >> a >> b;

	vector<int> res;

	char curr = a[0];
	for (int i = 1; i < n; i++) {
		if (curr == a[i]) continue;
		res.emplace_back(i - 1);
		curr = a[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (curr == b[i]) continue;
		res.emplace_back(i);
		curr = b[i];
	}

	cout << res.size();
	for (int x : res) {
		cout << ' ' << x + 1;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
