#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int t, n, k1, k2, st1[N], st2[N];
bool vis[N];
vector<int> adjList[N];

void solve() {
	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int x;
	set<int> st1, st2;

	cin >> k1;
	for (int i = 1; i <= k1; i++) {
		cin >> x;
		st1.insert(x);
	}

	cin >> k2;
	for (int i = 1; i <= k2; i++) {
		cin >> x;
		st2.insert(x);
	}

	int sv;

	cout << "B " << *st2.begin() << endl;
	cin >> sv;

	queue<int> q;
	q.push(sv);
	vis[sv]  = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (st1.count(v)) {
			int ev;

			cout << "A " << v << endl;
			cin >> ev;

			if (st2.count(ev)) {
				cout << "C " << v << endl;
			}
			else {
				cout << "C " << -1 << endl;
			}
			return;
		}

		for (int u : adjList[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			q.push(u);
		}
	}
	
	cout << "C " << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
			vis[i] = false;
		}

		solve();
	}

	return 0;
}
