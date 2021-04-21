#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 505;
int n, m, a[N], b[N];
int dp[N], tran[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		int k = 0;
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[j] = dp[k] + 1;
				tran[j] = k;
			}
			else if (b[j] < a[i] && dp[k] < dp[j]) {
				k = j;
			}
		}
	}


	int s = 0;
	for (int i = 1; i <= m; i++) {
		s = (dp[i] > dp[s]) ? i : s;
	}

	cout << dp[s] << '\n';

	deque<int> res;
	while (s != 0) {
		res.push_front(b[s]);
		s = tran[s];
	}
	for (int x : res) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
