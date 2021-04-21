#include <bits/stdc++.h>
using namespace std;
int t, n;
string str, pat;

int solve() {
	cin >> n >> str >> pat;

	map<char, set<char>> to;
	for (int i = 0; i < n; i++) {
		if (str[i] > pat[i]) {
			return -1;
		}
		if (str[i] == pat[i]) {
			continue;
		}

		to[str[i]].insert(pat[i]);
	}

	int cnt = 0;
	for (char c = 'a'; c < 't'; c++) {
		if (!to.count(c)) continue;

		char mn = *to[c].begin();
		for (char t : to[c]) {
			if (t == mn) continue;
			to[mn].insert(t);
		}

		cnt += 1;
	}

	return cnt;
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
