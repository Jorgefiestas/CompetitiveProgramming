#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	cin >> n;

	if (n <= 1) {
		cout << 1 << '\n';
		return 0;
	}

	int f = 2;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i - 1; j++) {
			f += j * (i - 1 - j) + 1;
		}
	}

	cout << f << '\n';

	return 0;
}
