#include <bits/stdc++.h>
using namespace std;
const int A = 26;
int from[A], to[A];
bool seen[A], vis[A];

void impossible() {
	cout << "NO\n";
	exit(0);
}

void connect(char f, char t) {
	int fi = f - 'a';
	int ti = t - 'a';

	if (from[ti] != -1 && from[ti] != fi) {
		impossible();
	}

	if (to[fi] != -1 && to[fi] != ti) {
		impossible();
	}

	from[ti] = fi;
	to[fi] = ti;
}

void process(const string &str) {
	int n = str.size();

	for (int i = 0; i < n; i++) {
		seen[str[i] - 'a'] = true;

		if (i > 0) {
			connect(str[i - 1], str[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(from, -1, sizeof from);
	memset(to, -1, sizeof to);

	int n;
	cin >> n;

	string str;
	for (int si = 0; si < n; si++) {
		cin >> str;
		process(str);
	}

	string ans;
	for (int i = 0; i < A; i++) {
		if (from[i] != -1 || !seen[i]) continue;
		int j = i;
		while (j != -1) {
			if (vis[j]) {
				impossible();
			}
			vis[j] = true;
			ans += (char) ('a' + j);
			j = to[j];
		}
	}

	for (int i = 0; i < A; i++) {
		if (seen[i] && !vis[i]) {
			impossible();
		}
	}

	cout << ans << '\n';
	return 0;
}
