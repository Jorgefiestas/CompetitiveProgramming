#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n;
	cin >> n;
	
	map<int, int> fr;

	int ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		fr[ai] += 1;
	}

	vector<int> freq;
	for (auto [k, v] : fr)
		freq.push_back(v);

	sort(freq.begin(), freq.end());
	int m = freq.size();


	int ans = INT_MAX;
	for (int i = 0; i < m; i++) {
		int can = n - (m - i) * freq[i];
		ans = min(ans, can);
	}

	return ans;
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
