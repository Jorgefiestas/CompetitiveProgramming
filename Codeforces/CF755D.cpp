#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	k = min(k, n - k);

	long long cnt = 1;
	int pos = 1;
	int inc = 0;

	for (int i = 0; i < n; i++) {
		if (pos + k > n && pos + k - n != 1) {
			inc += 1;
			cnt += (long long) 2 * inc;
			pos = pos + k - n;
		}
		else {
			cnt += (long long) (2 * inc + 1);
			pos += k;
		}
		cout << cnt << ' ';
	}
	cout << '\n';

	return 0;
}
