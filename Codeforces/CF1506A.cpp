#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	long long n, m, x;
	while (t--) {
		cin >> n >> m >> x;

		x -= 1;
		long long c = x / n;
		long long r = x % n;
		cout << r * m + c + 1 << '\n';
	}

	return 0;
}
