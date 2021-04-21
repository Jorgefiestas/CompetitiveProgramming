#include <bits/stdc++.h>
using namespace std;

int myLog(int x, int y) {
	if (y == 1) 
		return 1e9;

	int ans = 0;
	while (x) {
		ans++;
		x /= y;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	int a, b;
	while (t--) {
		cin >> a >> b;

		int ans = 1e9;
		for (int i = 0; i < ans; i++) {
			ans = min(ans, i + myLog(a, b + i));
		}
		cout << ans << '\n';
	}

	return 0;
}
