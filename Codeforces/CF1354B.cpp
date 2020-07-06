#include <bits/stdc++.h>
using namespace std;
int t;
string s;

int solve() {
	cin >> s;

	int l[3] = {-1, -1, -1};
	
	int ans = INT_MAX;
	for (int i = 0; i < s.size(); i++) {
		int c = s[i] - '1';
		l[c] = i;

		int mn = *min_element(l, l + 3);
		if (mn >= 0) {
			ans = min(ans, i - mn + 1);
		}
	}

	return (ans == INT_MAX) ? 0 : ans;
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
