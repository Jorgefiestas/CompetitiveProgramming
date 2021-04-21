#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, mn[N], mx[N];
string s, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> s >> t;

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (j >= m || s[i] != t[j]) continue;
		mn[j] = i;
		j += 1;
	}

	j = m - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (j < 0 || s[i] != t[j]) continue;
		mx[j] = i;
		j -= 1;
	}

	int ans = 0;
	for (int i = 1; i < m; i++) {
		ans = max(ans, mx[i] - mn[i - 1]);
	}

	cout << ans << '\n';

	return 0;
}
