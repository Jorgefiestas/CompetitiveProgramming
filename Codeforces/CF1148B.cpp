#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, ta, tb, k;
int a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> ta >> tb >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	if (k >= n) {
		cout << -1 << endl;
		return  0;
	}

	sort(a, a + n);
	sort(b, b + m);

	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int* fb = lower_bound(b, b + m, a[i] + ta);

		if (fb == b + m || distance(fb, b + m) <= k - i) {
			cout << -1 << endl;
			return 0;
		}
		
		ans = max(ans, *(fb + k - i) + tb);
	}

	cout << ans << endl;

	return 0;
}
