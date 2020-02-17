#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, q, s, ans[N + 5];

struct node {
	vector<pair<node*, long long>> adjList;
	pair<int, int> range;
};
using pni = pair<node*, long long>;
using pin = pair<long long, node*>;

node planets[N + 5];
node st1[4 * N + 5], st2[4 * N + 5];

void build1(int v, int tl, int tr) {
	st1[v].range = {tl, tr};
	if (tl == tr) {
		st1[v].adjList.push_back({planets + tl, 0});
		return;
	}
	int tm = (tl + tr) / 2;
	build1(v * 2, tl, tm);
	build1(v * 2 + 1, tm + 1, tr);
	st1[v].adjList.push_back({st1 + v * 2, 0});
	st1[v].adjList.push_back({st1 + v * 2 + 1, 0});
}

void build2(int v, int tl, int tr) {
	st2[v].range = {tl, tr};
	if (tl == tr) {
		planets[tl].adjList.push_back({st2 + v, 0});
		return;
	}
	int tm = (tl + tr) / 2;
	build2(v * 2, tl, tm);
	build2(v * 2 + 1, tm + 1, tr);
	st2[v * 2].adjList.push_back({st2 + v, 0});
	st2[v * 2 + 1].adjList.push_back({st2 + v, 0});
}

void query1(int v, int tl, int tr, int l, int r, int idx, int w) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		planets[idx].adjList.push_back({st1 + v, w});
		return;
	}
	int tm = (tl + tr) / 2;
	query1(v * 2, tl, tm, l, min(tm, r), idx, w);
	query1(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, idx, w);
}

void query2(int v, int tl, int tr, int l, int r, int idx, int w) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		st2[v].adjList.push_back({planets + idx, w});
		return;
	}
	int tm = (tl + tr) / 2;
	query2(v * 2, tl, tm, l, min(tm, r), idx, w);
	query2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, idx, w);
}

unordered_map<node*, long long> dist;

void dijkstra() {
	priority_queue<pin, vector<pin>, greater<pin>> Q;

	Q.push({0, planets + s});
	dist[planets + s] = 0;

	while (!Q.empty()) {
		pin curr = Q.top();
		Q.pop();
		if (dist.count(curr.second) && dist[curr.second] != curr.first) {
			continue;
		}
		
		node* v = curr.second;
		long long d = curr.first;
		for (pni u : v->adjList) {
			if (!dist.count(u.first) || d + u.second < dist[u.first]) {
				dist[u.first] = d + u.second;
				Q.push({dist[u.first], u.first});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q >> s;

	build1(1, 1, n);
	build2(1, 1, n);

	for (int i = 1; i <= n; i++) {
		planets[i].range = {i, i};
	}

	int qu, v, u, l, r, w;
	for (int i = 0; i < q; i++) {
		cin >> qu;
		if (qu == 1) {
			cin >> v >> u >> w;
			planets[v].adjList.push_back({planets + u, w});
		}
		else {
			cin >> v >> l >> r >> w;
			if (qu == 2) {
				query1(1, 1, n, l, r, v, w);
			}
			else {
				query2(1, 1, n, l, r, v, w);
			}
		}
	}

	dijkstra();

	for (int i = 1; i <= n; i++) {
		long long ans = dist.count(planets + i) ? dist[planets + i] : -1;
		cout << ans << ' ';
	}
	cout << endl;

	return 0;
}
