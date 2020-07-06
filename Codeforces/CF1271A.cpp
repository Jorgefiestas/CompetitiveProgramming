#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;

int main() {
	cin >> a >> b >> c >> d >> e >> f;
	
	int ans = 0;
	if (e >= f) {
		int fts = min(a, d);
		int sts = min({b, c, d - fts});
		ans = fts * e + sts * f;
	}
	if (e <= f) {
		int sts = min({b, c, d});
		int fts = min(a, d - sts);
		ans = max(ans, fts * e + sts * f);
	}

	cout << ans << endl;
	
	return 0;
}
