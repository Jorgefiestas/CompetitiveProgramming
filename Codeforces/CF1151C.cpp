#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long l, r;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int mul(int x, int y) {
	return (x * 1LL * y) % mod;
}

int sume(int x, int y) {
	return mul(add(x, y), sub(y, sub(x, 1)));
}

int sumo(int x, int y) {
	return sub(mul(add(x, y), sub(y, sub(x, 1))), sub(y, sub(x, 1)));
}

int calc(long long n) {
	long long so = 1;
	long long se = 1;
	bool even = false;

	int ans = 0;
	long long k = 0;
	for (long long i = 1; k + i <= n; i += i) { 
		if (even) {
			ans = add(ans, sume(se, add(se, (i - 1) % mod)));
			se = add(se, i % mod);
		}
		else {
			ans = add(ans, sumo(so, add(so, (i - 1) % mod)));
			so = add(so, i % mod);
		}
		even  = !even;
		k += i;
	}

	long long rem = n - k;

	if (!rem) {
		return ans;
	}

	rem--;

	if (even) {
		int ee = add(se, rem % mod);
		ans = add(ans, sume(se, ee));
	}
	else {
		int eo = add(so, rem % mod);
		ans = add(ans, sumo(so, eo));
	}

	return ans;
}

int main(){
	cin >> l >> r;

	cout << sub(calc(r), calc(l - 1)) << '\n';

    return 0;
}
