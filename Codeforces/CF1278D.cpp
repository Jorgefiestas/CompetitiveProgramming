#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 5e5 + 100;
int n, dsu[N];
pii seg[N];

int root(int x) {
	while (x != dsu[x]) {
		dsu[x] = dsu[dsu[x]];
		x = dsu[x];
	}
	return x;
}

void join(int a, int b) {
	a = root(a);
	b = root(b);
	dsu[a] = b;
}

bool poss() {
	int cnt = 0;

	set<pii> ends;
	for (int i = 0; i < n; i++) {
		int l = seg[i].first;
		int r = seg[i].second;

		auto it = ends.upper_bound({l, 0});

		while (it != ends.end()) {
			pii p = *it;
			if (p.first > r) break;
			int j = p.second;
			if (root(i) == root(j)) {
				return false;
			}
			join(i, j);
			cnt += 1;
			it++;
		}

		ends.insert({r, i});
	}

	return cnt == n - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		dsu[i] = i;
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seg[i].first >> seg[i].second;
	}
	sort(seg, seg + n);

	if (poss()) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
