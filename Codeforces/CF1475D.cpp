#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n;
	long long m;

	cin >> n >> m;

	vector<int> a(n + 1);
	vector<long long> bg, sm;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int imp;
	for (int i = 1; i <= n; i++) {
		cin >> imp;

		if (imp == 1) sm.emplace_back(a[i]);
		else bg.emplace_back(a[i]);
	}

	sort(sm.begin(), sm.end(), greater<int>());
	sort(bg.begin(), bg.end(), greater<int>());
	sm.insert(sm.begin(), 0);
	bg.insert(bg.begin(), 0);

	for (int i = 1; i < sm.size(); i++) {
		sm[i] += sm[i - 1];
	}

	int j = (int) sm.size() - 1;

	int ans = INT_MAX;
	long long sum = 0;
	for (int i = 0; i < bg.size(); i++) {
		sum += bg[i];

		while (j > 0 && sum + sm[j - 1] >= m) {
			j -= 1;
		}

		if (sum + sm[j] >= m) {
			ans = min(ans, i * 2 + j);
		}
	}

	return ans != INT_MAX ? ans : -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
