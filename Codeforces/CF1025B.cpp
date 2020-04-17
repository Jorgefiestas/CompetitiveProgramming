#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1.5e5 + 100;
int n;
pii a[N];

bool validWCD(int d) {
	for (int i = 1; i < n; i++) {
		if (a[i].first % d && a[i].second % d) {
			return false;
		}
	}
	return true;
}

int check(int x) {
	for (int d = 2; d * d <= x; d++) {
		if (x % d) continue;
		if (validWCD(d)) {
			return d;
		}
		while (x % d == 0) {
			x /= d;
		}
	}

	if (x > 1 && validWCD(x)) {
		return x;
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	int wcd = check(a[0].first);
	wcd = max(wcd, check(a[0].second));

	cout << wcd << '\n';

	return 0;
}
