#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string str;

void solve() {
	cin >> n >> k;
	cin >> str;

	map<char, int> cnt;
	for (char c : str) {
		cnt[c]++;
	}

	string ans;

	sort(str.begin(), str.end());

	char kmx = str[k - 1];
	if (kmx != str[0] || k == n) {
		cout << kmx << '\n';
		return;
	}

	if (str[k] == str[n - 1]) {
		cout << str[0];
		for (int i = 0; i < (n - 1) / k; i++) {
			cout << str[k];
		}
		cout << '\n';
		return;
	}

	cout << str[0];
	for (int i = k; i < n; i++) {
		cout << str[i];
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
