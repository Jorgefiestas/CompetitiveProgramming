#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n;
pii points[105];
vector<int> rows[1005], cols[1005];
bool vis[1002][1002];

void dfs(int x, int y) {
	vis[x][y] = true;

	for (int ny : rows[x]) {
		if (vis[x][ny]) continue;
		dfs(x, ny);
	}

	for (int nx : cols[y]) {
		if (vis[nx][y]) continue;
		dfs(nx, y);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin  >> points[i].first >> points[i].second;
		rows[points[i].first].push_back(points[i].second);
		cols[points[i].second].push_back(points[i].first);
	}

	int cnt = -1;
	for (int i = 0; i < n; i++) {
		int x = points[i].first;
		int y = points[i].second;
		
		if (vis[x][y]) continue;
		cnt++;

		dfs(x, y);
	}

	cout << cnt << endl;
}
