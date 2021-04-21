#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, x;
string str;
bool ans[N];

void impossible() {
	cout << -1 << '\n';
}

void solve() {
	cin >> str >> x;
	n = str.size();

	for (int i = 0; i < n; i++) {
		ans[i] = true;
	}

	for (int i = 0; i < x; i++) {
		bool from = false;

		for (int j = i; j < n; j += x) {
			if (str[j] == '1') continue;
			if (j - x >= 0) {
				ans[j - x] = false;
			}
			if (j + x < n) {
				ans[j + x] = false;
			}
		}

		for (int j = i; j < n; j += x) {
			if (str[j] == '0') continue;

			bool lft = false;
			bool rgt = false;
			if (j - x >= 0) {
				lft = ans[j - x];
			}
			if (j + x < n) {
				rgt = ans[j + x];
			}

			if (!lft && !rgt) {
				return impossible();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i];
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
