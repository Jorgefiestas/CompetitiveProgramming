#include <bits/stdc++.h>
using namespace std;
int t, n;
string str;

void solve() {
	cin >> n >> str;

	for (int i = 0; i < n; i++) {
		cout << str[i + i];
	}
	cout << '\n';
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
