#include <bits/stdc++.h>
using namespace std;
const int N = 1025;
int t, n, s[N], ns[N];

int solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n);

	for (int k = 1; k <= 1024; k++) {
		for (int i = 0; i < n; i++) {
			ns[i] = s[i] ^ k;
		}

		sort(ns, ns + n);

		bool eq = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != ns[i]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			return k;
		}
	}

	return -1;
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
