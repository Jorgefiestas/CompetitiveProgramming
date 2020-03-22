#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 100;
string s, t;
int mem[N][N];
pair<int, int> to[N][N];
bool vis[N][N];

int dp(int i, int j) {
	if (i == s.size() || j == t.size()) {
		return 0;
	}
	if (vis[i][j]) {
		return mem[i][j];
	}
	vis[i][j] = true;

	int ans = dp(i + 1, j);
	to[i][j] = {1, 0};

	if (dp(i, j + 1) > ans) {
		ans = dp(i, j + 1);
		to[i][j] = {0, 1};
	}

	if (s[i] == t[j] && dp(i + 1, j + 1) + 1 > ans) {
		ans = dp(i + 1, j + 1) + 1;
		to[i][j] = {1, 1};
	}

	return mem[i][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	int l = dp(0, 0);

	int i = 0, j = 0;
	while (i < s.size() && j < t.size()) {
		if (to[i][j].first && to[i][j].second) {
			cout << s[i];
		}

		int ni = i + to[i][j].first;
		int nj = j + to[i][j].second;
		i = ni, j = nj;
	}
	cout << endl;

	return 0;
}
