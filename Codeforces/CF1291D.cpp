#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int A = 26;
int n, q, cnt[N][A];
string str;

bool query(int l, int r) {
	if (r - l + 1 == 1 || str[l] != str[r]) {
		return true;
	}

	int dif = 0;
	for (int i = 0; i < A; i++) {
		if (cnt[r][i] - cnt[l - 1][i]) {
			dif += 1;
		}
	}
	
	return dif > 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	str = '0' + str;
	n = str.size() - 1;

	cin >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			cnt[i][j] += cnt[i - 1][j];
		}
		cnt[i][str[i] - 'a'] += 1;
	}

	int l, r;
	for (int qi = 0; qi < q; qi++) {
		cin >> l >> r;
		if (query(l, r)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
