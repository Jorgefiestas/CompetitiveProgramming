#include <bits/stdc++.h>
using namespace std;
int n;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		return false;
	}

	return true;
}

int main() {
	cin >> n;

	if (isPrime(n)) {
		cout << 1 << '\n';
		cout << n << '\n';
		return 0;
	}

	int p1 = n;
	while (!isPrime(p1)) {
		p1--;
	}

	n = n - p1;
	if (isPrime(n)) {
		cout << 2 << '\n';
		cout << p1 << ' ' << n << '\n';
		return 0;
	}

	int p2, p3;
	for (int i = 2; i < n; i++) {
		if (isPrime(i) && isPrime(n - i)) {
			p2 = i;
			p3 = n - i;
			break;
		}
	}

	cout << 3 << '\n';
	cout << p1 << ' ' << p2 << ' ' << p3 << '\n';

	return 0;
}
