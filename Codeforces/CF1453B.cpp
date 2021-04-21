#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n;
long long a[N];

long long solve() {
	cin >> n;

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (i > 1) {
			sum += (abs(a[i] - a[i - 1]));
		}
	}

	if (n <= 2) {
		return 0;
	}

	long long ans = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		long long can = sum;

		if (i > 1) {
			can -= abs(a[i] - a[i - 1]);
		}
		if (i < n) {
			can -= abs(a[i + 1] - a[i]);
		}
		if (i > 1 && i < n) {
			can += abs(a[i + 1] - a[i - 1]);
		}

		ans = min(ans, can);
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
