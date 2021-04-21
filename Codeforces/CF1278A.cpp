#include <bits/stdc++.h>
using namespace std;
int t, cnt[26];
string p, h;

bool check(int si) {
	memset(cnt, 0, sizeof cnt);
	
	for (int i = 0; i < p.size(); i++) {
		cnt[p[i] - 'a'] += 1;
		cnt[h[si + i] - 'a'] -= 1;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			return false;
		}
	}

	return true;
}

bool solve() {
	cin >> p >> h;

	int it = (int) h.size() - (int) p.size();
	for (int i = 0; i <= it; i++) {
		if (check(i)) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
