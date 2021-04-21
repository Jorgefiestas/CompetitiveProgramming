#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, f[N], b[N], idx[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		idx[f[i]] = i;
		cnt[f[i]]++;
	}

	bool amb = false;
	bool imp = false;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		imp = imp || !cnt[b[i]];
		amb = amb || cnt[b[i]] > 1;
	}

	if (imp) {
		cout << "Impossible" << '\n';
		return 0;
	}

	if (amb) {
		cout << "Ambiguity" << '\n';
		return 0;
	}

	cout << "Possible" << '\n';

	for (int i = 1; i <= m; i++) {
		cout << idx[b[i]] << ' ';
	}
	cout << '\n';

	return 0;
}
