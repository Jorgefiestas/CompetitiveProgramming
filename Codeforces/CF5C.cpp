#include <bits/stdc++.h>
using namespace std;
int b, n;
string str;
map<int, int> pref;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	n = str.size();

	pref[0] = -1;

	int ans = 0;
	int occ = 1;
	for (int i = 0; i < n; i++) {
		b += (str[i] == '(') ? 1 : -1;

		if (b < 0) {
			b = 0;
			pref.clear();
			pref[0] = i;
			continue;
		}

		if (str[i] == '(') {
			pref[b] = i;
		}
		else {
			if (pref.count(b)) {
				int can = i - pref[b];

				if (can > ans) {
					ans = can;
					occ = 0;
				}
				if (can == ans) {
					occ += 1;
				}
			}
		}
	}

	cout << ans << ' ' << occ << '\n';

	return 0;
}
