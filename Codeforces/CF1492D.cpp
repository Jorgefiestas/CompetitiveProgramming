#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a, b, k;
bool x[N], y[N];

void print(bool num[]) {
	for (int i = n - 1; i >= 0; i--)
		cout << num[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> k;
	n = a + b;

	if (k > a || (b == 1 && k > 0)) {
		cout << "No\n";
		return 0;
	}

	for (int i = 1; i <= b - 1; i++) {
		x[n - i] = 1;
		y[n - i] = 1;
	}

	if (b == 1) {
		x[n - 1] = 1;
		y[n - 1] = 1;
	}
	else {
		x[k] = 1;
		y[0] = 1;
	}

	cout << "Yes\n";

	print(x);
	print(y);

	return 0;
}
