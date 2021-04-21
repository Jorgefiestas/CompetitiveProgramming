#include <bits/stdc++.h>
using namespace std;
int t, n, c0, c1, h;
string str;

int solve() {
	cin >> n >> c0 >> c1 >> h;
	cin >> str;

	int cnt[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		cnt[str[i] - '0'] += 1;
	}

	c0 = min(c0, h + c1);
	c1 = min(c1, h + c0);

	return cnt[0] * c0 + cnt[1] * c1;
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
