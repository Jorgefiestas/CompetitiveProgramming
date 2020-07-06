#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int A = 27;
int n;
string str;

int cnt[A];
int q[A][A], mx[A][A];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> str;

	int ans = 0;

	int idx = 0;
	while (idx < n && str[idx] == str[0]) {
		idx++;
		ans++;
	}

	if (idx == n) {
		cout << 0 << '\n';
		return 0;
	}

	ans -= 1;
	for (int i = 0; i < n; i++) {
		int a = str[i] - 'a';
		cnt[a] += 1;

		for (int b = 0; b < A; b++) {
			if (!cnt[b] || b == a) continue;
			int can = cnt[a] - cnt[b] + mx[a][b];
			ans = max(ans, can);
		}

		for (int b = 0; b < A; b++) {
			if (b == a) continue;
			mx[b][a] = max(mx[b][a], q[b][a]);
			q[b][a] = cnt[a] - cnt[b];
		}
	}

	cout << ans << '\n';

	return 0;
}
