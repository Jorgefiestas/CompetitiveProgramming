#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, a[N], g[N * N];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n * n; i++) {
		cin >> g[i];
	}

	sort(g, g + n * n, greater<int>());

	a[0] = g[0];
	int idx = 1;

	map<int, int> cnt;

	for (int i = 1; i < n * n; i++) {
		if (cnt[g[i]]) {
			cnt[g[i]] -= 1;
			continue;
		}

		a[idx] = g[i];

		for (int j = 0; j < idx; j++) {
			int gd = gcd(a[idx], a[j]);
			cnt[gd] += 2;
		}

		idx += 1;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
