#include <bits/stdc++.h>
using namespace std;
int n, m, c, num[10];
int vis[10005];
int par[10005];
char tran[10005];
string ans;

void solve() {
	queue<int> Q;

	for (int i = 0; i < m; i++) {
		if (num[i] == 0) {
			continue;
		}
		Q.push(num[i] % n);
		if (vis[num[i] % n] == c) {
			continue;
		}
		
		vis[num[i] % n] = c;
		par[num[i] % n] = -1;
		tran[num[i] % n] = '0' + num[i];
	}

	bool found = false;
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();

		if (v == 0) {
			break;
		}

		for (int i = 0; i < m; i++) {
			int u = (v * 10 + num[i]) % n;
			if (vis[u] != c) {
				Q.push(u);
				vis[u] = c;
				par[u] = v;
				tran[u] = num[i] + '0';
			}
		}
	}
	
	if (vis[0] != c) {
		ans = "-1";
		return;
	}

	ans = tran[0];
	int v = par[0];
	while (v != -1) {
		ans += tran[v];
		v = par[v];
	}
	reverse(ans.begin(), ans.end());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m) {
		bool in[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int t;

		for (int i = 0; i < m; i++) {
			cin >> t;
			in[t] = true;
		}
		int j = 0;
		for (int i = 0; i < 10; i++) {
			if (!in[i]) {
				num[j++] = i;
			}
		}

		m = j;

		c++;
		solve();
		cout << "Case " << c << ": " << ans << '\n';
	}

	return 0;
}
