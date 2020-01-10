#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m, k, in, fi = -1;
int r[10005];
bool vis[10005], iq[10005];
pii points[10005];
vector<int> row[10005], col[10005];

void BFS() {
	deque<int> Q;
	
	memset(r, 1, sizeof r);

	Q.push_front(in);
	r[in] = 0;

	while (!Q.empty()) {
		int v = Q.front();
		Q.pop_front();

		if(vis[v]) continue;
		vis[v] = true;

		int x = points[v].first;
		int y = points[v].second;

		for (int idx : row[x]) {
			if (idx == v || vis[idx]) continue;

			int ty = points[idx].second;
			if (ty != y + 1 && ty != y - 1) {
				if(iq[idx]) continue;
				Q.push_back(idx);
				r[idx] = min(r[idx], r[v] + 1);
				iq[idx] = true;
			}
			else {
				Q.push_front(idx);
				r[idx] = r[v];
				iq[idx] = true;
			}
		}

		for (int idx : col[y]) {
			if (idx == v || vis[idx]) continue;

			int tx = points[idx].first;
			if (tx != x + 1 && tx != x - 1) {
				if(iq[idx]) continue;
				Q.push_back(idx);
				iq[idx] = true;
				r[idx] = min(r[idx], r[v] + 1);
			}
			else {
				Q.push_front(idx);
				r[idx] = r[v];
				iq[idx] = true;
			}
		}

		for (int d : {-2, -1, 1, 2}) {
			if (y + d >= 0) {
				for (int idx : col[y + d]) {
					if (vis[idx] || iq[idx])
						continue;
					iq[idx] = true;
					Q.push_back(idx);
					r[idx] = min(r[idx], r[v] + 1);
				}
			}
			if (x + d >= 0) {
				for (int idx : row[x + d]) {
					if (vis[idx] || iq[idx])
						continue;
					iq[idx] = true;
					Q.push_back(idx);
					r[idx] = min(r[idx], r[v] + 1);
				}
			}
		}
	}
}
	

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		row[x].emplace_back(i);
		col[y].emplace_back(i);
		if (x == 1 && y == 1) {
			in = i;
		}
		if (x == n && y == m) {
			fi = i;
		}
		points[i] = {x, y};
	}

	int os = 0;
	for (int i = 0; i < k; i++) {
		int x = points[i].first;
		int y = points[i].second;

	}

	BFS();

	int ans = INT_MAX;
	for (int i = 0; i < k; i++) {
		if (!vis[i]) continue;
		int x = points[i].first;
		int y = points[i].second;

		if (x == n && y == m) {
			ans = r[i];
			break;
		}

		if (x == n || y == m || x == n - 1 || y == m - 1) {
			ans = min(r[i] + 1, ans);
		}
	}

	if (ans != INT_MAX) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
