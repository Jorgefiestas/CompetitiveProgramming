#include <bits/stdc++.h>
using namespace std;
long long k;
const string str = "codeforces";

long long exp(long long x, int y) {
	long long ans = 1;
	while (y) {
		if (y & 1) {
			ans *= x;
		}
		x *= x;
		y >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;

	long long p;
	for (p = 1; p <= 40; p++) {
		if (exp(p, 10) >= k) break;
	}

	if (p == 1) {
		cout << str << '\n';
		return 0;
	}

	int cnt = 0;
	long long n = exp(p - 1, 10);
	while (n < k) {
		n = n / (p - 1) * p;
		cnt++;
	}

	for (char c : str) {
		for (int i = 1; i <= p - 1; i++) {
			cout << c;
		}
		if (cnt) {
			cout << c;
			cnt--;
		}
	}
	cout << '\n';

	return 0;
}
