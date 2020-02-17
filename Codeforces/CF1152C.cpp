#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<int> divisors;

void find_divisors(int x) {
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			divisors.push_back(i);
			divisors.push_back(x / i);
		}
	}
}

int main() {
	cin >> a >> b;

	if (a < b) {
		swap(a, b);
	}

	find_divisors(a - b);

	long long lcm = LLONG_MAX;
	int mnk = -1;
	for (long long g : divisors) {
		int k = ((b + g - 1) / g) * g - b;
		long long temp = 1LL * (a + k) * (b + k) / g;
		if (lcm >= temp) {
			lcm = temp;
			mnk = k;
		}
	}

	cout << max(0, mnk) << endl;
	
	return 0;
}
