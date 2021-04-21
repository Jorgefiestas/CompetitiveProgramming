#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int ans = 0;
	int ki, ai;
	for (int i = 0; i < n; i++) {
		cin >> ki >> ai;
		ans = max(ans, ki + 1);
		while (ai > 1) {
			ki += 1;
			ai = (ai + 3) / 4;
		}
		ans = max(ans, ki);
	}

	cout << ans << '\n';

	return 0;
}
