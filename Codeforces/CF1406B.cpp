#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, a[N];

long long solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, greater<int>());

	long long ans = LLONG_MIN;

	for (int i = 0; i < 5; i += 2) {
		long long prod = 1;

		for (int j = 0; j <= i; j++) {
			prod *= (long long) a[j];
		}
		for (int j = 0; j < 4 - i; j++) {
			prod *= (long long) a[n - 1 - j];
		}

		ans = max(ans, prod);
	}
			

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
