#include <bits/stdc++.h>
using namespace std;
int t;
string str;

int solve() {
	cin >> str;

	int ans = INT_MAX;
	for (char f = '0'; f <= '9'; f++) {
		for (char s = '0'; s <= '9'; s++) {
			int cnt = 0;
			int curr = 0;
			char pat[] = {f, s};
			for (char c : str) {
				if (c == pat[curr]) {
					curr = 1 - curr;
				}
				else {
					cnt += 1;
				}
			}

			if (curr == 1 && f != s) {
				cnt += 1;
			}

			ans = min(cnt, ans);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cout << solve() << endl;
	}

	return 0;
}
