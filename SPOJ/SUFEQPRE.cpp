#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int t, z[N];
string str;

void zeta() {
	memset(z, 0, sizeof z);
	int l = 0, r = 0;
	for (int i = 1; i < str.size(); i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> str;
		zeta();

		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (i + z[i] == str.size()) {
				cnt++;
			}
		}

		cout << "Case " << ti << ": " << cnt << '\n';
	}

	return 0;
}
