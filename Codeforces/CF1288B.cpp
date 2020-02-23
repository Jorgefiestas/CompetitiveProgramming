#include <bits/stdc++.h>
using namespace std;
long long t, a, b;

int main() {
	cin >> t;

	while (t--) {
		cin >> a >> b;

		long long ans = 0;
		for (int i = 10; i - 1 <= b; i *= 10) {
			ans += a;
		}
		cout << ans << endl;
	}

	return 0;
}
