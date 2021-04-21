#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int t, n, m;

bool solve() {
	cin >> n >> m;

	vector<pii> tblocked;
	vector<pii> blocked;

	for (int i = 0; i < m; i++) {
		int r, c;
		cin >> r >> c;
		tblocked.push_back({c, r});
	}

	sort(tblocked.begin(), tblocked.end());

	for (int i = 0; i < m; i++) {
		if (i < m - 1 && tblocked[i + 1].first == tblocked[i].first) {
			blocked.push_back({tblocked[i].first, 0});
		}
		blocked.push_back(tblocked[i]);
	}

	int state = 0;
	int last = 0;

	for (auto [c, s] : blocked) {
		if (state && (c - last) % 2) {
			state = 3 - state;
		}

		if (state == 0) {
			state = s;
		}
		else {
			if (state != 3 - s) 
				return false;
			state = 0;
		}

		last = c;
	}

	return state == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
