#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[100005], b[100005];
bool vis[1000005];
int idx[1000005];

long long solve() {
	long long cnt = 0;
	int lr = -1;
	int rm = 0;

	for (int i = 0; i < m; i++) {
		if (vis[b[i]]) {
			cnt++;
		}
		else {
			long long k = idx[b[i]] - 1 - rm;
			cnt += 2 * k + 1; 

			for (int j = idx[b[i]] - 1; j > lr; j--) {
				vis[a[j]] = true;
			}
			lr = idx[b[i]] - 1;
		}
		rm++;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		memset(vis, 0, sizeof vis);
		memset(idx, 0, sizeof idx);

		cin >> n >> m;
		
		for (int i = 0; i< n; i++) {
			cin >> a[i];
			idx[a[i]] = i + 1;
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		cout << solve() << '\n';
	}

	return 0;
}
