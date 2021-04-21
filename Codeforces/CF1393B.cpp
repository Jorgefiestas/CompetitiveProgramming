#include <bits/stdc++.h>
using namespace std;
int t;
string str;

int solve() {
	cin >> str;

	vector<int> groups;

	int curr = str[0];
	int cnt =  0;

	for (char c : str) {
		if (c == curr) {
			cnt += 1;
		}
		else {
			if (curr == '1') {
				groups.emplace_back(cnt);
			}
			cnt = 1;
			curr = c;
		}
	}
	if (curr == '1') {
		groups.emplace_back(cnt);
	}

	sort(groups.begin(), groups.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < groups.size(); i++) {
		if (i % 2) continue;
		ans += groups[i];
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
