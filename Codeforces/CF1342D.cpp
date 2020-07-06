#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, k, cnt[N], c[N];
vector<vector<int>> sol(1);

int first_available(int s) {
	int l = 0;
	int r = sol.size() - 1;

	int ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;

		int cap = c[s] - sol[m].size();
		if (cap > 0) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	if (ans == -1) {
		sol.push_back({});
		ans = sol.size() - 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	int m;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		cnt[m] += 1;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}

	for (int s = k; s > 0; s--) {
		if (!cnt[s]) continue;

		int idx = first_available(s);
		while (cnt[s]) {
			if (c[s] == sol[idx].size()) {
				if (idx == sol.size() - 1) {
					sol.push_back({});
				}
				idx++;
				continue;
			}

			sol[idx].emplace_back(s);
			cnt[s]--;
		}
	}

	cout << sol.size() << '\n';
	for (auto vec : sol) {
		cout << vec.size();
		for (int x : vec) {
			cout << ' ' << x;
		}
		cout << '\n';
	}

	return 0;
}
