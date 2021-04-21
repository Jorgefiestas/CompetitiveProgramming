#include <bits/stdc++.h>
using namespace std;

void solve() {
	string str;
	cin >> str;

	vector<deque<int>> occ(26);
	vector<bool> used(26, 1);

	for (int i = 0; i < str.size(); i++) {
		int ci = str[i] - 'a';
		occ[ci].push_back(i);
		used[ci] = false;
	}

	string ans;
	for (int i = 0; i < 26; i++) {
		int nc = -1;

		int ml = INT_MAX;
		for (int c = 0; c < 26; c++) {
			if (used[c]) continue;

			if (occ[c].front() < ml) {
				nc = c;
			}
			ml = min(ml, occ[c].back());
		}

		if (nc == -1) break;

		used[nc] = true;
		ans += (char)(nc + 'a');

		for (int c = 0; c < 26; c++) {
			if (used[c]) continue;
			while (occ[c].front() < occ[nc].front()) {
				occ[c].pop_front();
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
