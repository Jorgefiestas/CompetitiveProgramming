#include <bits/stdc++.h>
using namespace std;

string solve() {
	int a, b, n;
	cin >> a >> b;
	n = a + b;

	string str;
	cin >> str;

	for (int i = 0; i < n; i++) {
		if (str[i] == '?') continue;

		int j = n - 1 - i;
		if (str[j] == '?') {
			str[j] = str[i];
		}
		else if (str[j] != str[i]) {
			return "-1";
		}
	}

	if (n % 2 && str[n / 2] == '?') {
		if (a % 2) str[n / 2] = '0';
		else str[n / 2] = '1';
	}

	for (int i = 0; i < n; i++) {
		if (str[i] == '0') a--;
		if (str[i] == '1') b--;
	}

	for (int i = 0; i < n; i++) {
		if (str[i] != '?') continue;
		int j = n - 1 - i;

		if (a > 0) {
			str[i] = str[j] = '0';
			a -= 2;
		}
		else {
			str[i] = str[j] = '1';
			b -= 2;
		}
	}

	if (a != 0 || b != 0)
		return "-1";

	return str;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
