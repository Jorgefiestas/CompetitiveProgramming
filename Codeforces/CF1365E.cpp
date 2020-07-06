#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n;
long long a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << a[0] << '\n';
		return 0;
	}
	if (n == 2) {
		cout << (a[0] | a[1]) << '\n';
		return 0;
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < j; k++) {
				ans = max(ans, a[i] | a[j] | a[k]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
