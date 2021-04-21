#include <bits/stdc++.h>
using namespace std;
int cnt[10];
string u;

string at_idx(int lst) {
	memset(cnt, 0, sizeof cnt);
	string ans;

	for (int i = 0; i < lst; i++) {
		ans += u[i];
		cnt[u[i] - '0'] += 1;
	}

	for (int i = 0; i < 10; i++) {
		if (cnt[i] > 2)
			return "-1";
	}

	if (lst == u.size())
		return ans;

	int d = -1;
	for (int i = u[lst] - '0' - 1; i >= 0; i--) {
		if (cnt[i] == 2)
			continue;
		d = i;
		break;
	}

	if (d == -1)
		return "-1";

	if (lst < u.size() && (lst > 0 || d > 0)) {
		ans += (char) (d + '0');
		cnt[d] += 1;
	}

	for (int i = lst + 1; i < u.size(); i++) {
		for (int d = 9; d >= 0; d--) {
			if (cnt[d] == 2) continue;
			ans += (char) ('0' + d);
			cnt[d] += 1;
			break;
		}
	}

	return ans;
}

string solve() {
	string ans = "-1";

	for (int i = u.size(); i >= 0; i--) {
		if (i < u.size() && u[i] == '0') continue; 
		ans = at_idx(i);
		if (ans != "-1") break;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> u) {
		cout << solve() << '\n';
	}

	return 0;
}
