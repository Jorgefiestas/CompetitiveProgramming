#include <bits/stdc++.h>
using namespace std;
int t;
long long n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		while (n % 2 == 0) {
			n >>= 1;
		}

		cout << (n > 1 ? "YES" : "NO") << '\n';
	}

	return 0;
}
