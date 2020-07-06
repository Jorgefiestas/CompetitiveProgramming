#include <bits/stdc++.h>
using namespace std;
string str;
map<char, int> cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	for (char c : str) {
		cnt[c]++;
	}

	char mid = 0;
	for (char a = 'a'; a <= 'z'; a++) {
		if (cnt[a] % 2 == 0) continue;

		for (char b = 'z'; b > a; b--) {
			if (cnt[b] % 2 == 0) continue;
			cnt[a]++;
			cnt[b]--;
			break;
		}

		if (cnt[a] % 2) {
			mid = a;
		}
	}

	string ans;
	for (char a = 'a'; a <= 'z'; a++) {
		for (int i = 0; i < cnt[a] / 2; i++) {
			ans += a;
		}
	}

	cout << ans;
	if (mid) {
		cout << mid;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
