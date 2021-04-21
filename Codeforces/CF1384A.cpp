#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, a[N];

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	string str[n + 1];

	for (int i = 0; i < max(1, a[0]); i++) {
		str[0] += 'a';
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < a[i - 1]; j++) {
			str[i] += str[i - 1][j];
		}

		for (int j = a[i - 1]; j < a[i]; j++) {
			char nc = (str[i - 1].size() <= j || str[i - 1][j] == 'b') ? 'a' : 'b';
			str[i] += nc;
		}

		if (!str[i].size()) {
			str[i] += (str[i - 1][0] == 'a') ? 'b' : 'a';
		}
	}

	for (int i = 0; i < a[n - 1]; i++) {
		str[n] += str[n - 1][i];
	}

	if (str[n].size() == 0) {
		str[n] += (str[n - 1][0] == 'a') ? 'b' : 'a';
	}

	for (int i = 0; i <= n; i++) {
		cout << str[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	while (t--) {
		solve();
	}

	return 0;
}
