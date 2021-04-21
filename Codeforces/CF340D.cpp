#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> n >> m >> x >> y >> a >> b;

	int g = gcd(a, b);
	a /= g;
	b /= g;

	int k = min(n / a, m / b);
	int lx = a * k;
	int ly = b * k;

	int px = x - (lx + 1) / 2;
	int py = y - (ly + 1) / 2;

	int qx = x + lx / 2;
	int qy = y + ly / 2;

	int dx = 0;
	int dy = 0;

	if (px < 0) {
		dx =  -px;
	}
	if (qx > n) {
		dx = n - qx;
	}

	if (py < 0) {
		dy = -py;
	}
	if (qy > m) {
		dy = m - qy;
	}

	px += dx;
	py += dy;
	qx += dx;
	qy += dy;

	cout << px << ' ' << py << ' ';
	cout << qx << ' ' << qy << '\n';

	return 0;
}
