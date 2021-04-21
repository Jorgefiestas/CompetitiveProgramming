#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, m, a[N], b[N];
set<int> can[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		for (int j = 0; j < n; j++) {
			can[j].insert(b[i]);
		}
	}


	for (int bt = 8; bt >= 0; bt--) {
		bool canEl = true;

		for (int i = 0; i < n; i++) {
			if (!(a[i] & (1 << bt))) continue;

			bool el = false;
			for (int x : can[i]) {
				if (x & (1 << bt)) continue;
				el = true;
			}

			if (!el) {
				canEl = false;
				break;
			}
		}

		if (!canEl) continue;

		for (int i = 0; i < n; i++) {
			if (can[i].size() == 1) continue;
			if (!(a[i] & (1 << bt))) continue;

			vector<int > toErase;

			for (int x : can[i]) {
				if (x & (1 << bt)) {
					toErase.emplace_back(x);
				}
			}

			if (toErase.size() != can[i].size()) {
				for (int x : toErase) {
					can[i].erase(x);
				}
			}
		}
	}

	int bor = 0;
	for (int i = 0; i < n; i++) {
		bor |= (a[i] & *can[i].begin());
	}

	cout << bor << '\n';

	return 0;
}
