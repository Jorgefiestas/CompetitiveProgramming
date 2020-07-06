#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld PI = 3.14159265358979;
int t, n;

ld solve() {
	cin >> n;
	n *= 2;

	ld angVar;

	if (n % 4 == 0) {
		angVar = PI * (180.0 / n) / 180;
	}
	else {
		angVar = PI * (180.0 / (2 * n)) / 180;
	}

	ld negX = 1e15;
	ld negY = 1e15;
	ld posX = -1e15;
	ld posY = -1e15;

	for (int j = 0; j < n; j++) {
		ld px = cos(2 * PI * j / n + angVar);
		ld py = sin(2 * PI * j / n + angVar);

		negX = min(negX, px);
		posX = max(posX, px);
		negY = min(negY, py);
		posY = max(posY, py);
	}

	ld opt2 = max(posX - negX, posY - negY);

	return (ld) opt2 / sin(PI / n) / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << fixed << setprecision(9) << solve() << '\n';
	}

	return 0;
}
