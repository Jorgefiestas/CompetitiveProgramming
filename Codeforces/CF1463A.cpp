#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;

bool solve() {
	cin >> a >> b >> c;
	int sum = a + b + c;

	if (sum % 9) 
		return false;

	return (a + b + c) / 9 <= min({a, b, c});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
