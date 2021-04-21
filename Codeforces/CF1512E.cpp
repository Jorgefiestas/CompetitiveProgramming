#include <bits/stdc++.h>
using namespace std;

long long sum(int l, int r) {
	return 1LL * (l + r) * (r - l + 1) / 2;
}

vector<int> solve() {
	int n, l, r;
	long long s;
	cin >> n >> l >> r >> s;

	int m = r - l + 1;
	long long mn = sum(1, m);
	long long mx = sum(n - m + 1, n);

	if (s < mn || s > mx) 
		return {-1};

	vector<int> ans(n);
	vector<bool> used(n + 1, 0);


	for (int i = 0; i < m; i++) {
		int idx = l + i - 1;

		int d = min(s - mn, (long long) (n - m));
		ans[idx] = m - i + d;

		mn += (long long) d;
		used[ans[idx]] = true;
	}

	int x = 1;
	for (int i = 0; i < l - 1; i++) {
		while (used[x]) x++;
		used[x] = true;
		ans[i] = x;
	}
	for (int i = r; i < n; i++) {
		while (used[x]) x++;
		used[x] = true;
		ans[i] = x;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		vector<int> ans = solve();
		for (int x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}
