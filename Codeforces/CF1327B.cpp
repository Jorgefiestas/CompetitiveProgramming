#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n;
vector<int> g[N];
bool occ[N];

void solve() {
	cin >> n;
	
	int k, p;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> p;
			g[i].emplace_back(p);
		}
	}

	int fp = 0;
	for (int i = 1; i <= n; i++) {
		bool got = false;
		for (int p : g[i]) {
			if (occ[p]) continue;
			occ[p] = true;
			got = true;
			break;
		}

		if (!got) {
			fp = i;
		}
	}

	int fg = 0;
	for (int i = 1; i <= n; i++) {
		if (occ[i]) continue;
		fg = i;
	}

	if (fp && fg) {
		cout << "IMPROVE\n";
		cout << fp << ' ' << fg << '\n';
	}
	else {
		cout << "OPTIMAL\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		for (int i = 0; i <= n; i++) {
			g[i].clear();
			occ[i] = false;
		}

		solve();
	}

	return 0;
}
