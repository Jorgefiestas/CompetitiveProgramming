#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	if (n & 1) {
		cout << 1 << ' ';
	}

	for (int i = n & 1; i < n; i += 2) {
		cout << i + 2 << ' ' << i + 1 << ' ';
	}
	cout << '\n';

	return 0;
}
