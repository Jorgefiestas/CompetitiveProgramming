#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n;

pii count(const string &str) {
	int o = 0;
	int z = 0;

	for (char c : str) {
		if (c == '1') {
			o++;
		}
		else {
			z++;
		}
	}

	return {z, o};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str, pat;

	cin >> n >> str >> pat;

	if (count(str) != count(pat)) {
		cout << -1 << '\n';
		return 0;
	}

	int ans = 0;

	int sav[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		if (str[i] == pat[i]) continue;

		int c = str[i] - '0';
		if (sav[1 - c]) {
			sav[1 - c] -= 1;
			sav[c] += 1;
		}
		else {
			ans += 1;
			sav[c] += 1;
		}
	}

	cout << ans << '\n';
	
	return 0;
}
