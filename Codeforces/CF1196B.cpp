#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, k, a, r[N];

int main() {
	ios_base::sync_with_stdio(0);
    cin >> t;

	while (t--) {
		cin >> n >> k;
		
		int ocnt = 0;
		int si = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a;

			if (a & 1) {
				ocnt++;
				r[si++] = i;
			}
		}

		if (ocnt < k || (ocnt - k) % 2) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) {
			cout << r[i] << ' ';
		}
		cout << n << '\n';
	}

    return 0;
}
