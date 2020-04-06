#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 205;
int n;
vector<int> adjList[N];

pii dfs(int v, int p) {
	int mx = 0;
	int fl = 0, sl = 0;
	for (int u : adjList[v])  {
		if (u == p) continue;
		pii q = dfs(u, v);
		if (q.first  + 1 > fl) {
			sl = fl;
			fl = q.first + 1;
		}
		else if (q.first + 1> sl) {
			sl = q.first + 1;
		}
		mx = max(q.second, mx);
	}
	mx = max(fl + sl, mx);
	return {fl, mx};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int u : adjList[i]) {
			pii q1 = dfs(u, i);
			pii q2 = dfs(i, u);
			ans = max(ans, q1.second * q2.second);
		}
	}

	cout << ans << endl;

	return 0;
}
