#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int n, k, b[N];
long long a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	k = (n + 1) / 2;

	int j = 0;
	for (int i = 0; i < 2 * n; i++) {
		a[i] = b[j];
		j = (j + 2) % n;
	}

	long long curr = 0;
	for (int i = 0; i < k; i++) {
		curr += a[i];
	}

	long long ans = curr;
	for (int i = k; i < 2 * n; i++) {
		curr -= a[i - k];
		curr += a[i];
		ans = max(ans, curr);
	}

	cout << ans << '\n';

	return 0;
}
