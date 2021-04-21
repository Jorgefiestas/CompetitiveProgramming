#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 100;
int n, m, fib[N];

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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fib[0] = 1;
	fib[1] = 1;
	for (int i = 1; i < N; i++) {
		fib[i] = add(fib[i - 1], fib[i - 2]);
	}

	cin >> n >> m;

	int ans = add(add(fib[n], fib[n]), add(fib[m], fib[m]));

	cout << sub(ans, 2) << '\n';

	return 0;
}
