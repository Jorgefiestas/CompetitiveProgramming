#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, pos[N];
int cnt[N], dsu[N];

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

bool solve() {
	cin >> n;

	int x;
	multiset<int, greater<int>> mx;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		pos[x] = i;
		cnt[i] = 1;
		mx.insert(1);
		dsu[i] = i;
	}
	dsu[n + 1] = 0;


	for (int i = 1; i <= n; i++) {
		int idx = pos[i];
		if (cnt[idx] != *mx.begin()) {
			return false;
		}

		mx.erase(mx.find(cnt[idx]));

		join(idx, idx + 1);
		if (root(idx)) {
			mx.erase(mx.find(cnt[root(idx)]));
			cnt[root(idx)] += 1;
			mx.insert(cnt[root(idx)]);
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
