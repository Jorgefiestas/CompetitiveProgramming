#include <bits/stdc++.h>
using namespace std;
int t, n;
string str;

int solve() {
	cin >> str;
	n = str.size();

	if (n % 2)
		return -1;

	int cnt[2] = {0, 0};
	for (char c : str) {
		cnt[c - '0'] += 1;
	}

	if (!cnt[0] || !cnt[1])
		return -1;

	return abs(cnt[1] - cnt[0]) / 2;
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
