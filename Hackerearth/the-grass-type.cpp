#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, A[N + 5];
vector<int> adjList[N + 5];

int sz[N + 5];
void calcSize(int v, int p) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		calcSize(u, v);
		sz[v] += sz[u];
	}
}

long long pcnt;
unordered_map<int, long long> cnt;
int t, st[N + 5], ft[N + 5], ver[N + 5];
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
			int w = ver[i];

			if (A[v] % A[w] == 0) {
				pcnt += cnt[A[v] / A[w]];
			}
		}
	    for(int i = st[u]; i < ft[u]; i++) {
			cnt[A[ver[i]]]++;
		}
	}

	pcnt += cnt[1];
	cnt[A[v]]++;

	ft[v] = t;

    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
			cnt[A[ver[i]]]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	calcSize(1, -1);

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	dfs(1, -1, 1);
	cout << pcnt << endl;

	return 0;
}
