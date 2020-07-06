#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, e[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> e[i];
		}

		sort(e + 1, e + n + 1);

		int grpsz = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			grpsz++;
			if (grpsz == e[i]) {
				grpsz = 0;
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
