#include <bits/stdc++.h>
using namespace std;
int t;
string str;

string solve() {
	cin >> str;
	int n = str.size();

	bool o = false;
	bool z = false;
	for (int i = 0; i < n; i++) {
		if (str[i] == '1') {
			o = true;
		}
		if (str[i] == '0') {
			z = true;
		}
	}

	if (!o || !z) {
		return str;
	}

	string ans;
	for (int i = 0; i < 2 * n; i++) {
		ans += (char) ('0' + i % 2);
	}

	return ans;
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
