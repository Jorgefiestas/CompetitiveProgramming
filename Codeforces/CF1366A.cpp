#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		int d = b - a;

		if (a < d) {
			cout << a << '\n';
			continue;
		}
		
		int na = a - d;
		int ans = d + (na / 3) * 2;
		if (na % 3 == 2) {
			ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
