#include <bits/stdc++.h>
using namespace std;
long long a, b, x, y, z;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	cin >> x >> y >> z;

	long long da = 2 * x + y;
	long long db = y + 3 * z;

	cout << max(da - a, 0LL) + max(db - b, 0LL) << '\n';

	return 0;
}
