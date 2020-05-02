#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[105];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}

	set<int> k_elements;
	for (int i = 0; i < n; i++) {
		k_elements.insert(a[i]);
	}
	if (k_elements.size() > k) {
		cout << -1 << '\n';
		return;
	}

	vector<int> ans;
	for (int x : k_elements) {
		ans.emplace_back(x);
	}
	while (ans.size() < k) {
		ans.push_back(a[0]);
	}

	cout << n * k << endl;
	for (int i = 0; i < n; i++) {
		for (int x : ans) {
			cout << x << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t; 

	while (t--) {
		solve();
	}

	return 0;
}
