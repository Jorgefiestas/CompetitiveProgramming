#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, a[N];

long long solve() {
	cin >> n; 

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long ans = 0;
	for (int i = n; i > 1; i--) {
		if (a[i] > a[i - 1]) continue;
		ans += a[i - 1] - a[i];
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
