#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, rnk[N], rtime[N];
vector<int> adjList[N];
long long res[N], bit[N];

long long bit_query(int idx) {
	long long ans = 0;
	while (idx > 0) {
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void bit_update(int idx, long long val) {
	while (idx < N) {
		bit[idx] += val;
		idx += idx & -idx;
	}
}

int sz[N];
void calSize(int v, int p) {
	sz[v] = 1;

	for (int u : adjList[v]) {
		if (u == p) continue;
		calSize(u, v);
		sz[v] += sz[u];
	}
}

int timer, st[N + 5], ft[N + 5], ver[N + 5];
void dfs(int v, int p, bool keep){
	ver[timer] = v;
	st[v] = timer++;

    int bigChild =  -1;

    for (int u : adjList[v]) {
       if (u == p) continue;

	   bigChild = (bigChild != -1 && sz[bigChild] > sz[u]) ? bigChild : u;
	}

    for (int u : adjList[v]) {
        if(u == p || u == bigChild) continue;
		dfs(u, v, 0);
	}

    if(bigChild != -1) {
        dfs(bigChild, v, 1);
	}

	ft[v] = timer;

    for(auto u : adjList[v]) {
		if(u == p || u == bigChild) continue;

	    for(int i = st[u]; i < ft[u]; i++) {
			int w = ver[i];
			bit_update(rnk[w], rtime[w]);
		}
	}


	res[v] = bit_query(rnk[v] - 1);
	bit_update(rnk[v], rtime[v]);

    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
			int w = ver[i];
			bit_update(rnk[w], -rtime[w]);
		}
	}
}


void solve() {
	int m, r, t, s;
	for (int i = 1; i <= n; i++) {
		cin >> m >> r >> t;
		if (m == -1) {
			s = i;
		}
		else {
			adjList[m].emplace_back(i);
		}
		rnk[i] = r;
		rtime[i] = t;
	}
	
	calSize(s, -1);
	dfs(s, -1, 0);

	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n) {
		timer = 0;
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
		}

		solve();
	}
}
