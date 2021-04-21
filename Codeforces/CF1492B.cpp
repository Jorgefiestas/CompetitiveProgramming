#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, idx[N], p[N];

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		idx[p[i]] = i;
	}

	vector<int> ans;

	int lst = n + 1;
	for (int x = n; x >= 1; x--) {
		if (idx[x] >= lst) continue;
		
		for (int i = idx[x]; i < lst; i++)
			ans.push_back(p[i]);
		lst = idx[x];
	}

	for (int x : ans) {
		cout << x << ' ';
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
