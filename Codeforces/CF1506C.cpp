#include <bits/stdc++.h>
using namespace std;

bool find(string &pat, string &str, int l, int r) {
	int m = r - l + 1;

	for (int i = 0; i <= str.size() - m; i++) {
		bool good = true;
		for (int j = 0; good && j < m; j++) {
			if (pat[l + j] == str[i + j]) continue;
			good = false;
		}
		if (good) return true;
	}
	return false;
}

int solve() {
	string a, b;
	cin >> a >> b;

	if (a.size() > b.size()) 
		swap(a, b);

	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i; j < a.size(); j++) {
			if (find(a, b, i, j)) {
				ans = max(ans, j - i + 1);
			}
		}
	}

	return a.size() + b.size() - 2 * ans;
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
