#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, sz[N + 5];
long long dcs[N + 5];
vector<int> adjList[N + 5];

void calSize(int v, int p) {
	int s = 1;

	for (int u : adjList[v]) {
		if (u == p) continue;
		calSize(u, v);
		s += sz[u];
	}

	sz[v] = s;
}

int t, dom, cnt[N + 5], st[N + 5], ft[N + 5], ver[N + 5];
long long ans, col[N + 5];
void dfs(int v, int p, bool keep){
	ver[t] = v;
	st[v] = t++;

    int bigChild = 0;

    for (int u : adjList[v]) {
       if (u == p) continue;
	   
	   bigChild = (sz[bigChild] > sz[u]) ? bigChild : u;
	}

    for (int u : adjList[v]) {
        if(u == p || u == bigChild) continue;
		dfs(u, v, 0); 
	}

    if(bigChild) {
        dfs(bigChild, v, 1);
	}

    for(auto u : adjList[v]) {
		if(u == p || u == bigChild) continue;

	    for(int i = st[u]; i < ft[u]; i++) {
			cnt[col[ver[i]]]++;
			if (col[ver[i]] == dom || cnt[col[ver[i]]] > cnt[dom]) {
				dom = col[ver[i]];
				ans = col[ver[i]];
			}
			else if (cnt[col[ver[i]]] == cnt[dom]) {
				ans += col[ver[i]];
			}
		}
	}

	cnt[col[v]]++;
	if (col[v] == dom || cnt[col[v]] > cnt[dom]) {
		dom = col[v];
		ans = col[v];
	}
	else if (cnt[col[v]] == cnt[dom]) {
		ans += col[v];
	}

	ft[v] = t;
	dcs[v] = ans;

    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
			cnt[col[ver[i]]]--;
			ans = 0;
			dom = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> col[i];
	}

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	calSize(1, -1);

	dfs(1, -1, 1);

	for (int i = 1; i <= n; i++) {
		cout << dcs[i] << ' ';
	}
	cout << endl;

	return 0;
}
