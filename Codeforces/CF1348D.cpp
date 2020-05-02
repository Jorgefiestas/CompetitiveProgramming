#include <bits/stdc++.h>
using namespace std;
int t, n;

void solve() {
	cin >> n;
	
	int b = 1, am = 1;
	vector<int> ans;
	int x;
	while (am < n) {
		int l = 0;
		int r = b;

		if (n -  am - b <= b) {
			ans.emplace_back(n - am - b);
			break;
		}


		int i;
		while (l <= r) {
			int m = (l + r) / 2;
			if (am + 2 * (b + m) <= n) {
				l = m + 1;
				i = m;
			}
			else {
				r = m - 1;
			}
		}

		b += i;
		am += b;
		ans.emplace_back(i);
	}

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}
