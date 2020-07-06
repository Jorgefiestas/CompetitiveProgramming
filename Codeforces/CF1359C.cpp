#include <bits/stdc++.h>
using namespace std;
int t;
long long xs, ys, xd, yd;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> xs >> ys >> xd >> yd;

		cout << (xd - xs) * (yd - ys) + 1 << '\n';
	}

	return 0;
}
