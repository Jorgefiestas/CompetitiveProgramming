#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m;
long long bal[N];
map<int, long long> ans[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b, d;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> d;
		bal[a] += (long long) d;
		bal[b] -= (long long) d;
	}

	int u = 1;
	int cnt = 0;
	for (int v = 1; v <= n; v++) {
		while (bal[v] > 0) {
			while (bal[u] >= 0) {
				u++;
			}
			long long mn = min(bal[v], -bal[u]);
			bal[v] -= mn;
			bal[u] += mn;

			ans[v][u] = mn;
			cnt += 1;
		}
	}

	cout << cnt << '\n';

	for (int v = 1; v <= n; v++) {
		for (auto p : ans[v]) {
			cout << v << ' ' << p.first << ' ' << p.second << '\n';
		}
	}
	
	return 0;
}
