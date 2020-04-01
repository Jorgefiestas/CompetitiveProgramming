#include <iostream>
using namespace std;
int t, a, b, c, d;
int x, y, x1, y1, x2, y2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		int dx = b - a;
		int dy = d - c;

		if (x1 == x2 && (a || b)) {
			cout << "NO" << endl;
			continue;
		}
		if (y1 == y2 && (c || d)) {
			cout << "NO" << endl;
			continue;
		}

		if (x + dx < x1 || x + dx > x2 || y + dy < y1 || y + dy >  y2) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}

	return 0;
}
