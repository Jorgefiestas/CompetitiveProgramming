#include <bits/stdc++.h>
using namespace std;

vector<long long> solve() {
	int n;
	cin >> n;

	vector<long long> b(n + 2);
	for (int i = 0; i < n + 2; i++) {
		cin >> b[i];
	}

	sort(b.begin(), b.end());

	long long sum = 0;
	for (int i = 0; i <= n; i++) {
		sum +=  b[i];
	}

	if (sum == 2 * b[n]) {
		b.pop_back();
		b.pop_back();
		return b;
	}

	bool good = false;
	vector<long long> ans;

	for (int i = 0; i <= n; i++) {
		if (!good  && sum - b[i] == b[n + 1]) {
			good = true;
			continue;
		}
		ans.emplace_back(b[i]);
	}

	if (!good)
		return {-1};

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		vector<long long> ans = solve();
		for (long long x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
