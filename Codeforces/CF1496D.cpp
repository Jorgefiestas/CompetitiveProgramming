#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n + 2);
	vector<int> lft(n + 2, 0);
	vector<int> rgt(n + 2, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int mx = 0;

	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			lft[i] = lft[i - 1] + 1;
		}
		mx = max(mx, lft[i]);
	}

	for (int i = n - 1; i > 0; i--) {
		if (a[i] > a[i + 1]) {
			rgt[i] = rgt[i + 1] + 1;
		}
		mx = max(mx, rgt[i]);
	}

	if (mx % 2) {
		cout << 0 << '\n';
		return 0;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (rgt[i] == mx && lft[i] == mx) {
			cnt += 1;
		}
		else if (rgt[i] == mx || lft[i] == mx) {
			cnt += 2;
		}

	}

	cout << (cnt > 1 ? 0 : cnt) << '\n';

	return 0;
}
