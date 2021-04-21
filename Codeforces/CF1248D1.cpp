#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 505;
int n, sc[N], mn[N];
string str;

int score() {
	sc[0] = 0;
	mn[0] = 0;

	for (int i = 0; i < n; i++) {
		sc[i + 1] = sc[i] + ((str[i] == '(') ? 1 : -1);
		mn[i + 1] = min(mn[i], sc[i + 1]); 
	}

	if (sc[n] != 0) {
		return 0;
	}

	int scre = 0;
	int mini = 0;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (mini >= 0  && scre + mn[n - i] >= 0) {
			ans += 1;
		}

		if (str[n - i - 1] == '(') {
			mini += 1;
			scre += 1;
		}
		else {
			mini = min(-1, mini - 1);
			scre -= 1;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> str;

	int ans = 0;
	pii res = {1, 1};
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			swap(str[i], str[j]);
			int scre = score();
			if (scre > ans) {
				ans = scre;
				res = {i + 1, j + 1};
			}
			swap(str[i], str[j]);
		}
	}

	cout << ans << '\n';
	cout << res.first << ' ' << res.second << '\n';

	return 0;
}
