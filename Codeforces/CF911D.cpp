#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
int n, m, a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	bool inv = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) continue;
			inv = !inv;
		}
	}

	cin >> m;

	int li, ri;
	for (int i = 0; i < m; i++) {
		cin >> li >> ri;
		if ((ri - li + 1) / 2 & 1) {
			inv = !inv;
		}
		if (inv) {
			cout << "odd\n";
		}
		else {
			cout << "even\n";
		}
	}

	return 0;
}
