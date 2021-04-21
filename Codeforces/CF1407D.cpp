#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int n, h[N], dp[N];
int bigger[N], smaller[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	stack<int> mn, mx;

	for (int i = 1; i <= n; i++) {
		while (!mn.empty() && h[i] <= h[mn.top()]) {
			mn.pop();
		}
		while (!mx.empty() && h[i] >= h[mx.top()]) {
			mx.pop();
		}

		smaller[i] = mn.empty() ? -1 : mn.top();
		bigger[i] = mx.empty() ? -1 : mx.top();

		mn.push(i);
		mx.push(i);
	}

	for (int i = 2; i <= n; i++) {
		int can = dp[i - 1] + 1;

		if (h[i - 1] < h[i]) {
			int j = i - 1;

			while (j != -1) {
				can = min(can, dp[j] + 1);
				if (h[j] >= h[i]) break;
				j = bigger[j];
			}
		}

		if (h[i - 1] > h[i]) {
			int j = i - 1;

			while (j != -1) {
				can = min(can, dp[j] + 1);
				if (h[j] <= h[i]) break;
				j = smaller[j];
			}
		}

		dp[i] = can;
	}

	cout << dp[n] << '\n';

	return 0;
}
