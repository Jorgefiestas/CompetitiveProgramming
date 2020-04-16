#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n);

		int i = 0;
		int j = n - 1;

		vector<int> sol;
		while (i <= j) {
			sol.emplace_back(a[i]);
			i++;

			if (i <= j) {
				sol.emplace_back(a[j]);
			}
			j--;
		}

		reverse(sol.begin(), sol.end());
		for (int x : sol) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}
