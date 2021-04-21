#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
int n, m, dsu[N];

int root(int idx) {
	while (dsu[idx] != idx) {
		dsu[idx] = dsu[dsu[idx]];
		idx = dsu[idx];
	}
	return idx;
}

void join(int a, int b) {
	int ra = root(a);
	int rb = root(b);
	dsu[ra] = rb;
}

struct Edg {
	int a, b, i, w;

	bool operator<(const Edg &other) const {
		if (w == other.w) {
			return i < other.i;
		}
		return w < other.w;
	}
};

Edg edg[M];

bool check(int x) {
	for (int i = 0; i < m; i++) {
		if (edg[i].i) continue;
		edg[i].w = x;
		break;
	}

	for (int v = 1; v <= n; v++) {
		dsu[v] = v;
	}

	sort(edg, edg + m);

	for (int i = 0; i < m; i++) {
		int a = edg[i].a;
		int b = edg[i].b;

		if (root(a) != root(b)) {
			if (edg[i].i == 0) return true;
			join(a, b);
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edg[i] = {a, b, i, c};
	}

	int l = 0;
	int r = 1e9;
	int ans = 0;

	while (l <= r) {
		int m = (l + r) / 2;

		if (check(m)) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
