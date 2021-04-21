#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, k;
	string str;

	cin >> n >> k;
	cin >> str;

	while (str.back() != '*') 
		str.pop_back();

	n = str.size();

	if (str.empty())
		return 0;

	str[n - 1] += 1;
	int ans = 1;

	for (int i = 0; i < n; i++) {
		if (str[i] != '*') continue;
		str[i] = 'x';
		ans += 1;
		break;
	}

	for (int i = 0; i < n - k - 1; i++) {
		if (str[i] != 'x') continue;

		for (int j = k; j > 0; j--) {
			if (str[i + j] != '*') continue;
			str[i + j] = 'x';
			ans += 1;
			break;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
