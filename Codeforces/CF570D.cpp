#include <bits/stdc++.h>
using namespace std;
const int N = 500000;
int n, m, he[N + 5], sz[N + 5], vh[N + 5];
char car[N + 5];
bool res[N + 5];
vector<int> queries[N + 5];
vector<int> adjList[N + 5];

void calcSize(int v) {
	sz[v] = 1;
	vh[v] += 1;
	for (int u : adjList[v]) {
		vh[u] = vh[v];
		calcSize(u);
		sz[v] += sz[u];
	}
}

int odd[N + 5];
unordered_map<int, int> cnt[N + 5];
int t, st[N + 5], ft[N + 5], ver[N + 5];

void dfs(int v, bool keep){
	ver[t] = v;
	st[v] = t++;

    int bigChild = 0;

    for (int u : adjList[v]) {
	   bigChild = (sz[bigChild] > sz[u]) ? bigChild : u;
	}

    for (int u : adjList[v]) {
        if(u == bigChild) continue;
		dfs(u, 0);
	}

    if(bigChild) {
        dfs(bigChild, 1);
	}

    for(auto u : adjList[v]) {
		if(u == bigChild) continue;

	    for(int i = st[u]; i < ft[u]; i++) {
			int w = ver[i];

			cnt[vh[w]][car[w]]++;
			if (cnt[vh[w]][car[w]] % 2) {
				odd[vh[w]]++;
			}
			else {
				odd[vh[w]]--;
			}
		}
	}

	cnt[vh[v]][car[v]]++;
	if (cnt[vh[v]][car[v]] % 2) {
		odd[vh[v]]++;
	}
	else {
		odd[vh[v]]--;
	}

	ft[v] = t;

	for (int q : queries[v]) {
		res[q] = (odd[he[q]] <= 1);
	}

    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
			int w = ver[i];
			cnt[vh[w]][car[w]]--;
			if (cnt[vh[w]][car[w]] % 2) {
				odd[vh[w]]++;
			}
			else {
				odd[vh[w]]--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	int v, h;
	for (int i = 2; i <= n; i++) {
		cin >> v;
		adjList[v].emplace_back(i);
	}

	for (int i = 1; i <= n; i++) {
		cin >> car[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> v >> h;
		queries[v].push_back(i);
		he[i] = h;
	}

	calcSize(1);
	dfs(1, 1);

	for (int i = 0; i < m; i++) {
		if (res[i]) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
