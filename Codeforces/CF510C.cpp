#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
string str[N];
int vis[26];
vector<int> adjList[N];

void impossible() {
	cout << "Impossible\n";
	exit(0);
}

stack<char> order;
void dfs(int v) {
	vis[v] = 1;
	for (int u : adjList[v]) {
		if (vis[u] == 1) impossible();
		if (vis[u] == 2) continue;
		dfs(u);
	}
	order.push(v + 'a');
	vis[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 1; i < n; i++) {
		string &cur = str[i];
		string &las = str[i - 1];

		bool pref = true;
		for (int j = 0; j < min(cur.size(), las.size()); j++) {
			if (cur[j] == las[j]) continue;
			pref = false;
			int u = las[j] - 'a';
			int v = cur[j] - 'a';
			adjList[u].emplace_back(v);
			break;
		}

		if (pref && las.size() > cur.size()) {
			impossible();
		}
	}

	for (int i = 0; i < 26; i++) {
		if (vis[i]) continue;
		dfs(i);
	}

	while (!order.empty()) {
		cout << order.top();
		order.pop();
	}
	cout << '\n';

	return 0;
}
