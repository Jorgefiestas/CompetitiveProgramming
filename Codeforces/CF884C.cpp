#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, c, p[N], len[N];
bool vis[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	long long score = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;

		len[c] = 1;
		int j = p[i];
		while (j != i) {
			vis[j] = true;
			len[c] += 1;
			j = p[j];
		}
		score += (long long) len[c] * len[c];
		c += 1;
	}

	if (c == 1) {
		cout << score << endl;
		return 0;
	}

	sort(len, len + c, greater<int>());
	score += 2LL * len[0] * len[1];

	cout << score << '\n';

	return 0;
}
