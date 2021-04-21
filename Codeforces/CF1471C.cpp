#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int t, n, m, cnt[N], c[N];

long long solve() {
	cin >> n >> m;

	int k;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		cnt[k] += 1;
	}

	for (int i = 1; i <= m; i++) {
		cin >> c[i];
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		pq.push(c[i]);

		for (int j = 0; j < cnt[i]; j++) {
			if (pq.top() < c[i]) {
				ans += pq.top();
				pq.pop();
				pq.push(c[i]);
			}
			else {
				ans += (long long) c[i];
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		cout << solve() << '\n';
	}

	return 0;
}
