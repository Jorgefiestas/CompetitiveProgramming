#include <bits/stdc++.h>
using namespace std;
int t;
string str;

bool solve() {
	cin >> str;

	int i = 0;
	for (; i < str.size() - 1; i++) {
		if (str[i] == '0') continue;
		if (str[i + 1] == '1') break;
	}

	for (; i < str.size() - 1; i++) {
		if (str[i] == '1') continue;
		if (str[i + 1] == '0')
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
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
