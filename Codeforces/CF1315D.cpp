#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n;
unordered_map<int, bool> vis;
pair<int, int> a[N];
unordered_map<int, int> dsu;

int root(int x) {
	if (!dsu.count(x)) {
		dsu[x] = x;
	}

	while (x != dsu[x]) {
		dsu[x] = dsu[dsu[x]];
		x = dsu[x];
	}
	return x;
}

void join(int x, int y) {
	int rootx = root(x);
	int rooty = root(y);
	dsu[rootx] = rooty;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	
	sort(a, a + n, greater<pair<int, int>>());

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		int ai = a[i].second;
		int ti = a[i].first;
		
		int nxt = root(ai);
		cnt += (nxt - ai) * 1LL * ti;
		join(nxt, nxt + 1);
	}

	cout << cnt << '\n';

	return 0;
}
