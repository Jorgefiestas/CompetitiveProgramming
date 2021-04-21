#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, x, pref[N];
string str;

int solve() {
	cin >> n >> x >> str;
	str = 't' + str;

	bool pres = false;
	for (int i = 1; i <= n; i++) {
		int val = (str[i] == '0') ? 1 : -1;
		pref[i] = pref[i - 1] + val;
		if (pref[i] == x) { 
			pres = true;
		}
	}

	if (pref[n] == 0) {
		return pres ? -1 : 0;
	}

	int sum = pref[n];
	int ans = x ? 0 : 1;

	for (int i = 1; i <= n; i++) {
		if (pref[i] < x && sum < 0) continue;
		if (pref[i] > x && sum > 0) continue;
		ans += ((x - pref[i]) % sum) ? 0 : 1;
	}

	return ans;
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
