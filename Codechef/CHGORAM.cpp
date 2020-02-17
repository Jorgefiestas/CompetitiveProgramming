#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, order, p[3];
long long cnt;
vector<vector<int>> adjList;

int bitUp[N], bitBC[N];
int smaller(int bit[], int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int bigger(int bit[], int idx) {
	return bit[0] - smaller(bit, idx);
}

void update(int bit[], int idx, int val) {
	while (idx < n + 5) {
		bit[idx] += val;
		idx += idx & -idx;
	}
	bit[0] += val;
}

int sz[N];
void calcSize(int v, int p) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		calcSize(u, v);
		sz[v] += sz[u];
	}
	update(bitUp, v, 1);
}

int timer, st[N], ft[N], ver[N];
void dfs(int v, int p, bool keep) {
	ver[timer] = v;
	st[v] = timer++;

	int bigChild = 0;

	for (int u : adjList[v]) {
		if (u == p) continue;
		if (sz[bigChild] < sz[u]) {
			bigChild = u;
		}
	}

	for (int u : adjList[v]) {
		if (u == p || u == bigChild) continue;
		dfs(u, v, 0);
	}

	if (bigChild) {
		dfs(bigChild, v, 1);
	}

	ft[v] = timer;

	update(bitUp, v, -1);

	for (int u : adjList[v]) {
		if (u == p || u == bigChild) continue;

		for (int t = st[u]; t < ft[u]; t++) {
			update(bitUp, ver[t], -1);
		}
		for (int t = st[u]; t < ft[u]; t++) {
			int w = ver[t];

			if (order == 0 && w > v) {
				cnt += (long long)(smaller(bitBC, v));
			}
			else if (order == 0 && w < v) {
				cnt += (long long)(bigger(bitBC, v));
			}
			else if (order == 1 && w < v) {
				cnt += (long long)(smaller(bitBC, v));
			}
			else if (order == 2 && w > v) {
				cnt += (long long)(bigger(bitBC, v));
			}
		}
		for (int t = st[u]; t < ft[u]; t++) {
			update(bitBC, ver[t], 1);
		}
	}

	if (order == 0) {
		cnt += smaller(bitBC, v) * 1LL * bigger(bitUp, v);
		cnt += bigger(bitBC, v) * 1LL * smaller(bitUp, v);
	}
	else if (order == 1) {
		cnt += smaller(bitBC, v) * 1LL * smaller(bitUp, v);
	}
	else if (order == 2) {
		cnt += bigger(bitBC, v) * 1LL * bigger(bitUp, v);
	}

	update(bitBC, v, 1);

	if (!keep) {
		for (int t = st[v]; t < ft[v]; t++) {
			int u = ver[t];
			update(bitUp, u, 1);
			update(bitBC, u, -1);
		}
	}
}

void solve() {
	cin >> n;
	cin >> p[0] >> p[1] >> p[2];

	if (p[0] < p[1] && p[2] < p[1]) {
		order = 1;
	}
	else if (p[0] > p[1] && p[2] > p[1]) {
		order = 2;
	}
	else {
		order = 0;
	}
	
	adjList.resize(n + 5);

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	calcSize(1, -1);
	dfs(1, -1, 1);

	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		adjList.clear();
		memset(bitUp, 0, sizeof bitUp);
		memset(bitBC, 0, sizeof bitBC);
		cnt = 0;
		timer = 0;
		solve();
	}

	return 0;
}
