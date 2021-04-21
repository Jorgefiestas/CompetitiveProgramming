#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 5e5 + 10;
int n, a[N];
int par[N], timer, tin[N], tout[N];
vector<int> adjList[N];
int erased[N];
 
void dfs(int v, int p) {
	tin[v] = ++timer;
	par[v] = p;
 
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
	}
 
	tout[v] = ++timer;
}
 
void keepST(int v) {
	erased[0] -= 1;
	erased[tin[v]] += 1;
	erased[tout[v] + 1] -= 1;
}
 
bool isAncestor(int v, const vector<pii> &vec, bool exc) {
	pii tv = {tin[v], exc ? INT_MAX : INT_MIN};
	auto it = upper_bound(vec.begin(), vec.end(), tv);
	return it != vec.end() && it->second <= tout[v];
}

bool comp(const int x, const int y) {
	return tin[x] < tin[y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for (int v = 1; v <= n; v++) {
		cin >> a[v];
	}
 
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, -1);

	map<int, vector<int>> st;
	for (int v = 1; v <= n; v++) {
		st[a[v]].emplace_back(v);
	}
 
	for (auto &[x, vrtx] : st) {
		sort(vrtx.begin(), vrtx.end(), comp);

		int mnL = INT_MAX;
		int mxR = INT_MIN;

		vector<pii> mst;
		for (int v : vrtx) {
			while (!mst.empty() && mst.back().second > tout[v]) {
				mst.pop_back();
			}
			mst.push_back({tin[v], tout[v]});
			mnL = min(mnL, tin[v]);
			mxR = max(mxR, tout[v]);
		}

		for (int v : vrtx) {
			if (isAncestor(v, mst, 1)) {
				for (int u : adjList[v]) {
					if (u != par[v] && isAncestor(u, mst, 0)) {
						erased[0] -= 1;
						erased[tin[u]] += 1;
						erased[tout[u] + 1] -= 1;
					}
				}
			}

			if (mnL < tin[v] || mxR > tout[v]) {
				erased[tin[v]] -= 1;
				erased[tout[v] + 1] += 1;
			}
		}
	}
 
	int ans = 0;
	for (int v = 1; v <= 2 * n; v++) {
		erased[v] += erased[v - 1];
		if (!erased[v]) ans++;
	}
 
	cout << ans / 2 << '\n';
 
	return 0;
}
