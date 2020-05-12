#include <bits/stdc++.h>
using namespace std;
const int N = 6010;
int n, con[N], dp[N][2];
vector<int> adjList[N];

void dfs(int v) {
	dp[v][1] = con[v];

	for (int u : adjList[v]) {
		dfs(u);
		dp[v][0] += max(dp[u][1], dp[u][0]);
		dp[v][1] += dp[u][0];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	set<int> st;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> con[i];
		st.insert(i);
	}

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		adjList[b].emplace_back(a);
		st.erase(a);
	}

	int s = *st.begin();

	dfs(s);
	cout << max(dp[s][0], dp[s][1]) << '\n';

	return 0;
}
