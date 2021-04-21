#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	while (t--) {
		int n, x;
		map<int, int> cnt;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x;
			cnt[x] += 1;
		}

		cout << n - cnt.begin()->second << '\n';
	}

	return 0;
}
