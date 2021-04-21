#include <bits/stdc++.h>
using namespace std;
int t;
long long d, k;

bool solve() {
	cin >> d >> k;

	long long d2 = d * d / (k * k);

	for (long long x = 1; x <= d; x++) {
		long long y = sqrt(d2 - x * x);
		if (y == x) {
			return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "Ashish\n";
		}
		else {
			cout << "Utkarsh\n";
		}
	}

	return 0;
}
