#include <bits/stdc++.h>
using namespace std;
int t, s;

int solve(int x) {
	if (x < 10) {
		return x;
	}
	return (x / 10) * 10 + solve(x % 10 + x / 10);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> s;
		cout << solve(s) << '\n';
	}

	return 0;
}
