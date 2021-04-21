#include <bits/stdc++.h>
using namespace std;
int t, cnt[27];
string s, p;

string solve() {
	cin >> s >> p;

	for (char c : s) {
		cnt[c - 'a'] += 1;
	}
	for (char c : p) {
		cnt[c - 'a'] -= 1;
	}

	char ini = p[0];
	char fd = p[0];
	for (char c : p) {
		if (c != ini) {
			fd = c;
			break;
		}
	}

	string ans;
	for (int i = 0; i < 26; i++) {
		if (i == ini - 'a' && fd <= ini) {
			ans += p;
		}
		for (int j = 0; j < cnt[i]; j++) {
			ans += (char) ('a' + i);
		}
		if (i == ini - 'a' && fd > ini) {
			ans += p;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		cout << solve() << '\n';
	}

	return 0;
}
