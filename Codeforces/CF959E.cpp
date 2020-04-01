#include <bits/stdc++.h>
using namespace std;
long long n;

int main() {
	cin >> n;
	n = n - 1;

	long long ans = 0;
	long long i = 1;
	while (n) {
		ans += i * ((n + 1) / 2);
		n >>= 1;
		i <<= 1;
	}

	cout << ans << endl;

	return 0;
}
