#include <bits/stdc++.h>
using namespace std;
int m, w, a[110];

int main() {
	cin >> w >> m;

	int idx = 0;
	while (m) {
		a[idx++] = m % w;
		m /= w;
	}

	bool poss = true;
	for (int i = 0; i <= 100; i++) {
		if (a[i] == w) {
			a[i + 1]++;
			a[i] = 0;
		}
		if (a[i] == 1 || a[i] == 0) continue;
		if (a[i] == w - 1) {
			a[i + 1]++;
		}
		else {
			poss = false;
			break;
		}
	}
	if (a[101]) {
		poss = false;
	}

	if (poss) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}
