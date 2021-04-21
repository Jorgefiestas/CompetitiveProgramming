#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;
const int N = 105;
int n, a[N];
long long k;
bool vis[N];

struct Dist {
	long long d = LLONG_MAX, s = LLONG_MAX;

	bool operator <(const Dist &dst) const {
		if (d == dst.d) {
			return s > dst.s;
		}
		return d < dst.d;
	}
};

Dist dst[N];

struct Pt {
	int x, y;
};

Pt pt[N];

long long dist(Pt a, Pt b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 2; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> pt[i].x >> pt[i].y;
	}

	dst[1] = {0, 0};

	while (!vis[n]) { 
		int v = -1;

		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			if (v == -1 || dst[i] < dst[v]) {
				v = i;
			}
		}

		vis[v] = true;
		dst[v].s += (long long) a[v];

		for (int u = 1; u <= n; u++) {
			if (vis[u]) continue;
			long long d = k * dist(pt[v], pt[u]);
			long long nd = dst[v].d + d - min(dst[v].s, d);
			long long ns = max(dst[v].s - d, 0LL);

			dst[u] = min(dst[u], {nd, ns});
		}
	}

	cout << dst[n].d << '\n';

	return 0;
}
