#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t;
string s, p;
int nxt[N][26];

int solve() {
	cin >> s >> p;
	int n = s.size();
	int m = p.size();
	
	memset(nxt[n - 1], -1, sizeof nxt[n - 1]);

	nxt[n - 1][s[n - 1] - 'a'] = n;
	for (int i = 0; i < n - 1; i++) {
		int c = s[i] - 'a';

		if (nxt[n - 1][c] == -1) {
			nxt[n - 1][c] = i + 1;
		}
		nxt[n - 1][c] = min(nxt[n - 1][c], i + 1);
	}

	for (int i = n - 2; i >= 0; i--) {
		int nc = s[i + 1] - 'a';
		nxt[i][nc] = 1;

		for (int c = 0; c < 26; c++) {
			if (c == nc) continue;
			if (nxt[i + 1][c] == -1) {
				nxt[i][c] = -1;
				continue;
			}
			nxt[i][c] = 1 + (nxt[i + 1][c] % n);
		}
	}
	
	int j = 0;
	while (j < n && s[j] != p[0]) {
		j += 1;
	}
	if (j == n) {
		return -1;
	}
	
	int ops = 1;

	for (int i = 1; i < m; i++) {
		int c = p[i] - 'a';
		
		if (nxt[j][c] == -1) {
			return -1;
		}

		j += nxt[j][c];
		if (j >= n) {
			j -= n;
			ops += 1;
		}

	}

	return ops;
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
