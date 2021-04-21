#include <bits/stdc++.h>
using namespace std;
const long long N = 1e12;
set<long long> cubes;

bool check(long long x) {
	for (long long a : cubes) {
		if (a >= x) break;
		long long b = x - a;

		if (cubes.count(b))
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (long long x = 1; x * x * x <= N; x++) {
		cubes.insert(x * x * x);
	}

	int t;
	cin >> t;
	
	long long x;
	while (t--) {
		cin >> x;

		if (check(x)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
