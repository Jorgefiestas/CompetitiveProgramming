#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 1e5 + 10;
int n, s;
vector<int> adjList[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int leafs = 0;
	for (int v = 1; v <= n; v++) {
		if (adjList[v].size() > 1) continue;
		leafs += 1;
	}

	cout << fixed << setprecision(9);
	cout << (ld) 2 * s / leafs << '\n';

	return 0;
}
