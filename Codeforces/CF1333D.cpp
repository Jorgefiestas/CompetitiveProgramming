#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, k;
string str;
vector<int> turn[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> str;

	int mn = 0, mx = 0;

	for (int i = 0; i <= n; i++) {
		int swps = 0;
		for (int j = 0; j < n - 1; j++) {
			if (str[j] == 'R' && str[j + 1] == 'L') {
				swps++;
				str[j] = 'L';
				str[j + 1] = 'R';
				turn[i].emplace_back(j + 1);
				j++;
			}
		}
		if (!swps) {
			break;
		}
		mx += swps;
		mn++;
	}

	if (k >= mn && k <= mx) {
		int vi = 0;
		while (k > mn - vi) {
			cout << 1 << ' ' << turn[vi].back() << '\n';
			turn[vi].pop_back();
			if (turn[vi].empty()) {
				vi++;
			}
			k--;
		}
		for (int i = vi; i < mn; i++) {
			cout << turn[i].size() << ' ';
			for (int x : turn[i]) {
				cout << x << ' ' ;
			}
			cout << '\n';
		}
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
