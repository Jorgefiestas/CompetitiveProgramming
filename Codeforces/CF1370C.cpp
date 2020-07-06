#include <bits/stdc++.h>
using namespace std;
int t, n;

bool solve() {
	cin >> n;

	if (n == 1) {
		return false;
	}
	if (n % 2 || n == 2) {
		return true;
	}

	int cnt = 0;
	while (n % 2 == 0) {
		n /= 2;
		cnt++;
	}

	int ocnt = 0;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			ocnt++;
		}
	}
	if (n > 1) {
		ocnt++;
	}

	if (ocnt == 1 && cnt == 1) {
		return false;
	}
	if (ocnt == 0 && cnt > 1) {
		return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "Ashishgup\n";
		}
		else {
			cout << "FastestFinger\n";
		}
	}

	return 0;
}
