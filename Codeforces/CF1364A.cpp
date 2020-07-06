#include <bits/stdc++.h>
using namespace std;
int t, n, x;

int solve() {
	cin >> n >> x;

	int pre = 0;
	int ans = -1;
	
	int a;
	int lst = 1000000;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pre = (pre + a) % x;
		if (pre) {
			ans = max(ans, i + 1);
			lst = min(lst, i);
		}
		else {
			ans = max(ans, i - lst);
		}
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
