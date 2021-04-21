#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n, k;
	string str;

	cin >> n >> k;
	cin >> str;

	if (k * 2 == n) 
		return false;

	for (int i = 0; i < k; i++) {
		if (str[i] != str[n - 1 - i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}

	return 0;
}
