#include <bits/stdc++.h>
using namespace std;
int t, n;

bool solve() {
	cin >> n;

	int cnt[3] = {0, 0, 0};

	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		cnt[x] += 1;
	}

	int a = 0;
	int b = 0;

	if (cnt[2] % 2) {
		if (cnt[1] < 2) {
			return false;
		}
		cnt[1] -= 2;
	}

	return cnt[1] % 2 == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
