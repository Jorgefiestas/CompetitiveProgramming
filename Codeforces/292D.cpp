#include <bits/stdc++.h>
using namespace std;
const int N  = 1e4 + 5;
using pii = pair<int, int>;
int n, m, k, dsu[505];
pii edges[N];

int root(int p) {
	while (p != dsu[p]) {
		dsu[p] = dsu[dsu[p]];
		p = dsu[p];
	}
	return p;
}

void join(int a, int b) {
	a = root(a);
	b = root(b);
	dsu[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> edges[i].first >> edges[i].second;
	}
	
	cin >> k;
	
	int l, r;
	for (int q = 0; q < k; q++) {
		cin >> l >> r;
		for (int i = 0; i <= n; i++) {
			dsu[i] = i;
		}

		int cnt = n;

		for (int i = 1; i <= m; i++) {
			if (i == l) { 
				i = r;
				continue;
			}
			if (root(edges[i].first) != root(edges[i].second)) {
				join(edges[i].first, edges[i].second);
				cnt--;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
