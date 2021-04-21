#include <bits/stdc++.h>
using namespace std;
int t, n;
string str;

int solve() {
	cin >> n >> str;

	int ans = 0;
	for (char x : str) {
		int d = x - '0';
		if (d % 2) {
			ans *= 10;
			ans += d;
		}
		if (ans > 10) break;
	}

	return (ans > 10) ? ans : -1;
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
