#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string a, b;

bool solve() {
	cin >> n >> k;
	cin >> a >> b;

	map<char, int> cnta, cntb;

	for (char c : a) {
		cnta[c] += 1;
	}
	for (char c : b) {
		cntb[c] += 1;
	}

	for (char c = 'a'; c <= 'z'; c++) {
		if (cnta[c] < cntb[c]) {
			return false;
		}

		char nxt = c + 1;
		int rem = cnta[c] - cntb[c];

		if (rem % k != 0) {
			return false;
		}
		cnta[nxt] += rem;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
