#include <bits/stdc++.h>
using namespace std;
int n, t;
string a, b, c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> t;
	cin >> a >> b;
	c = a;

	int teq = n - t;
	int eq = 0;
	for (int i = 0; i < n; i++) {
		eq += (a[i] == b[i]) ? 1 : 0;
		if (teq) {
			c[i] = a[i];
			teq -= 1;
		}
	}

	if (teq * 2 > n - eq) {
		cout << -1 << '\n';
		return 0;
	}

	int teqa = teq;
	int teqb = teq;

	char can[] = {'a', 'b', 'c'};

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		if (teqa) {
			c[i] = a[i];
			teqa -= 1;
		}
		else if (teqb) {
			c[i] = b[i];
			teqb -= 1;
		}
		else {
			int j = 0;
			while (can[j] == a[i] || can[j] == b[i]) {
				j += 1;
			}
			c[i] = can[j];
		}
	}

	cout << c << '\n';

	return 0;
}
