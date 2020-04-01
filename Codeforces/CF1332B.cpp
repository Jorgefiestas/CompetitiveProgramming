#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int t, n, ans[N], spf[N];

void sieve() {
	for (int i = 1; i < N; i++) {
		spf[i] = i;
	}

	for (int i = 2; i * i < N; i++) {
		if (spf[i] != i) continue;
		for (int j = i * i; j < N; j += i) {
			spf[j] = min(spf[j], i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> t;

	while (t--) {
		cin >> n;

		int x, num = 1;
		unordered_map<int, int> con;
		for (int i = 0; i < n; i++) {
			cin >> x;

			if (!con.count(spf[x])) {
				con[spf[x]] = num++;
			}
			ans[i]  = con[spf[x]];
		}

		cout << num - 1 << '\n';
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ' ;
		}
		cout << '\n';
	}

	return 0;
}
