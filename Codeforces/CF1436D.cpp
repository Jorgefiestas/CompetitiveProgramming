#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N], cnt[N], mx[N], sum[N];
vector<int> adjList[N];

void dfs(int v) {
	if (adjList[v].empty()) {
		sum[v] = a[v];
		mx[v] = a[v];
		cnt[v] = 1;
		return;
	}

	cnt[v] = 0;
	mx[v] = 0;
	sum[v] = a[v];

	for (int u : adjList[v]) {
		dfs(u);
		cnt[v] += cnt[u];
		sum[v] += sum[u];
		mx[v] = max(mx[v], mx[u]);
	}

	mx[v] = max(mx[v], (sum[v] + cnt[v] - 1) / cnt[v]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int pi;
	for (int i = 2; i <= n; i++) {
		cin >> pi;
		adjList[pi].emplace_back(i);
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dfs(1);
	cout << mx[1] << '\n';

	return 0;
}
