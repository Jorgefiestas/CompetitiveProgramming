#include <bits/stdc++.h>
using namespace std;
long long l, r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> r;

	long long ans = 0;
	bool state = false;
	for (int i = 62; i >= 0; i--) {
		if (state) {
			ans |= (1LL << i);
			continue;
		}

		bool lb = !!(l & (1LL << i));
		bool rb = !!(r & (1LL << i));
		if (lb != rb && !state) {
			state = true;
			i++;
		}
	}

	cout << ans << '\n';

	return 0;
}
