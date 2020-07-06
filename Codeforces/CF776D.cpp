#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, m, q;
int dsu[N], dis[N];
map<string, int> id;

int root(int idx) {
	if (idx == -1) {
		return -1;
	}

	while (idx != dsu[idx]) {
		dsu[idx] = dsu[dsu[idx]];
		idx = dsu[idx];
	}
	return idx;
}

bool join(int a, int b) {
	int ra = root(a);
	int rb = root(b);
	int rda = root(dis[ra]);
	int rdb = root(dis[rb]);

	if (ra == rb) {
		return true;
	}
	if (rda == rb) {
		return false;
	}

	if (rda == -1) {
		swap(ra, rb);
		swap(rda, rdb);
	}

	dsu[rb] = ra;

	if (rdb == -1) {
		dis[rb] = rda;
	}
	else {
		dsu[rdb] = rda;
	}

	return true;
}

bool rjoin(int a, int b) {
	int ra = root(a);
	int rb = root(b);
	int rda = root(dis[ra]);
	int rdb = root(dis[rb]);

	if (ra == rdb) {
		return true;
	}
	if (ra == rb) {
		return false;
	}

	if (rda == -1 && rdb == -1) {
		dis[ra] = rb;
		dis[rb] = ra;
	}
	else if (rda == -1 || rdb == -1) {
		if (rda == -1) {
			swap(ra, rb);
			swap(rda, rdb);
		}
		
		dis[rb] = ra;
		dsu[rb] = rda;
	}
	else {
		dsu[rda] = rb;
		dsu[rdb] = ra;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;

	for (int i = 0; i <= n; i++) {
		dsu[i] = i;
		dis[i] = -1;
	}

	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		id[word] = i;
	}

	int t, a, b;
	string sa, sb;
	for (int i = 0; i < m; i++) {
		cin >> t >> sa >> sb;
		int a = id[sa];
		int b = id[sb];

		bool pos = false;
		if (t == 1) {
			pos = join(a, b);
		}
		else {
			pos = rjoin(a, b);
		}

		if (pos) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	for (int i = 0; i < q; i++) {
		cin >> sa >> sb;
		int a = id[sa];
		int b = id[sb];

		if (root(a) == root(b)) {
			cout << 1 << '\n';
		}
		else if (root(dis[root(a)]) == root(b)) {
			cout << 2 << '\n';
		}
		else {
			cout << 3 << '\n';
		}
	}

	return 0;
}

