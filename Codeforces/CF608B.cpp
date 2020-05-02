#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, pref[N];
string s, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	n = s.size();
	m = t.size();

	for (int i = 0; i < n; i++) {
		if(s[i] == '1') {
			pref[i]++;
		}
		pref[i + 1] += pref[i];
	}

	long long ans = 0;
	for (int i = 0; i < m; i++) {
		int l = max(0, i + n - m);
		int r = min(i, n - 1);

		int tans;
		if (t[i] == '0') {
			tans = pref[r] - ((l > 0) ? pref[l - 1] : 0);
		}
		else {
			tans = (r - l + 1) - (pref[r] - ((l > 0) ? pref[l - 1] : 0));
		}
		ans += (long long) tans;
	}

	cout << ans << '\n';

	return 0;
}
