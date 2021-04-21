#include <bits/stdc++.h>
using namespace std;
int t, n;
string str;

void solve() {
	cin >> n >> str;
	sort(str.begin(), str.end());
	cout << str << '\n';
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
