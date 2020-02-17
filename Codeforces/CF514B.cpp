#include <bits/stdc++.h>
using namespace std;
int n, xo, yo;
set<pair<int, int>> lines;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> xo >> yo;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		x -= xo;
		y -= yo;
		if (!x && ! y) {
			continue;
		}

		bool neg = false;
		if (x < 0) {
			neg = !neg;
			x = -x;
		}
		if (y < 0) {
			neg = !neg;
			y = -y;
		}
		if (!x || !y) {
			neg = false;
		}

		int g = gcd(x, y);
		x /= g;
		y /= g;

		if (neg) {
			lines.insert({-x, y});
		}
		else {
			lines.insert({x, y});
		}
	}

	cout << max(1, (int) lines.size()) << endl;

	return 0;
}
