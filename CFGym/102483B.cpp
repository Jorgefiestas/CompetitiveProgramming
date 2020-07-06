#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 4e5 + 100;
int n, e[N], nxt[N];
set<int> prv[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 1; i <= n; i++) {
		int m, x;
		cin >> e[i] >> m;

		for (int j = 0; j < m; j++) {
			cin >> x;
			prv[i].insert(x);
			nxt[x]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!nxt[i]) {
			pq.push({e[i], i});
		}
	}

	int ans = 0;
	int cnt = n - 1;
	while (!pq.empty()) {
		int v = pq.top().second;
		int t = pq.top().first;
		pq.pop();

		ans = max(ans, cnt + t);

		for (int u : prv[v]) {
			nxt[u]--;
			if (!nxt[u]) {
				pq.push({e[u], u});
			}
		}

		cnt--;
	}

	cout << ans << '\n';
	return 0;
}
