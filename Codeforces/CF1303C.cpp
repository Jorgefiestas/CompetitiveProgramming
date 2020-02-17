#include <bits/stdc++.h>
using namespace std;
int t, idx;
bool vis[30];
string pass, ans;
set<int> connected[30];

bool dfs(int v, int p) {
	ans += (char)('a' + v);
	vis[v] = true;

	for (int x : connected[v]) {
		if (x == p) continue;
		if (vis[x]) {
			return false;
		}
		if (!dfs(x, v)) {
			return false;
		}
	}

	return true;
}

void solve() {
	cin >> pass;

	for (int i = 0; i < pass.size() - 1; i++) {
		char c = pass[i];
		connected[c - 'a'].insert(pass[i + 1] - 'a');
		connected[pass[i + 1] - 'a'].insert(c - 'a');
	}

	vector<int> border;
	for (int i = 0; i <= 'z' - 'a'; i++) {
		if (connected[i].size() > 2) {
			cout << "NO\n";
			return;
		}
		else if (connected[i].size() < 2) {
			border.push_back(i);
		}
	}
	
	for (int x : border) {
		if (vis[x]) continue;

		if (!dfs(x, -1)) {
			cout << "NO\n";
			return;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (!vis[i]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	cout << ans << '\n';

}

int main() {
	cin >> t;

	while (t--) {
		for (int i = 0; i < 30; i++) {
			connected[i].clear();
		}
		memset(vis, 0, sizeof vis);
		ans = "";
		solve();
	}

	return 0;
}
