#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int t, n, k, a[N * N], res[N][N];

long long solve() {
	cin >> n >> k;

	for (int i = 1; i <= n * k; i++) {
		cin >> a[i];
	}

	long long ans = 0;

	int mid = n / 2;
	int j = n * k - mid;

	for (int i = 0; i < k; i++) {
		ans += (long long) a[j];
		j -= mid + 1;
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
