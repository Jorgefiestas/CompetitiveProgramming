#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int X = 1e4 + 100;
int n, x, val[N];
int  dp[X];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> x;

	int c;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		val[i] = c * (n - i + 1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = x; j >= 0; j--) {
			int nj = j + val[i];
			if (nj <= x) {
				dp[nj] = max(dp[nj], dp[j] + 1);
			}
		}
	}


	int ans = *max_element(dp, dp + x + 1);
	cout << ans << '\n';

	return 0;
}
