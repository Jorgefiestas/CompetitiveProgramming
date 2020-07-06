#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, k;
long long cnt[26];
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> k;
	n = s.size();

	if (k > (long long) n * (n + 1) / 2) {
		cout << "No such line.\n";
		return 0;
	}

	vector<int> valid;
	for (int i = 0; i < n; i++) {
		valid.emplace_back(i);
	}

	int it = 0;
	vector<int> pos[26];
	while (k > 0) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < 26; i++) {
			pos[i].clear();
		}

		for (int i : valid) {
			if (i + it >= n) continue;
			pos[s[i + it] - 'a'].emplace_back(i);
			cnt[s[i + it] - 'a'] += (long long) (n - i - it);
		}
		it += 1;

		int i;
		for (i = 0; i < 26; i++) {
			if (cnt[i] >= k) {
				break;
			}
			k -= cnt[i];
		}

		cout << (char) (i + 'a');
		k -= pos[i].size();

		valid.clear();
		for (int x : pos[i]) {
			valid.emplace_back(x);
		}
	}
	cout << '\n';

	return 0;
}
