#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, k, a[N];
long long b[N];

long long query(int l, int r) {
	if (l == r) {
		return k - 1;
	}

	long long ans = b[r - 1] - b[l];
	ans += (long long) a[l + 1] - 2;
	ans += (long long) (k - a[r - 1] - 1);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 2; i < n; i++) {
		b[i] = b[i - 1];
		b[i] += (long long) (a[i + 1] - 2 - a[i - 1]);
	}

	int l, r;
	for (int qi = 0; qi < q; qi++) {
		cin >> l >> r;
		cout << query(l, r) << '\n';
	}

	return 0;
}
