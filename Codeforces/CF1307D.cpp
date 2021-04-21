#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 100;
int n, m, k, sp[N], toRoot[N], toHome[N];
vector<int> adjList[N];

void bfs(int arr[], int s) {
	queue<int> q;

	arr[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int u : adjList[v]) {
			if (u == s || arr[u]) continue;
			arr[u] = arr[v] + 1;
			q.push(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		cin >> sp[i];
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	bfs(toRoot, 1);
	bfs(toHome, n);

	multiset<int> dist;
	set<pii> sorted;
	for (int i = 0; i < k; i++) {
		int v = sp[i];
		dist.insert(toHome[v]);
		sorted.insert({toRoot[v], v});
	}


	int ans = 0;
	for (pii p :  sorted) {
		int v = p.second;
		int d = p.first;

		dist.erase(dist.find(toHome[v]));
		if (dist.empty()) {
			break;
		}

		int mxdist = *prev(dist.end());

		int can = d + mxdist + 1;
		can = min(toRoot[n], can);
		ans = max(can, ans);
	}

	cout << ans << '\n';

	return 0;
}
