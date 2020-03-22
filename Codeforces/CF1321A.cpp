#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n;
bool a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int cnta = 0, cntb = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] && !b[i]) {
			cnta++;
		}
		else if (!a[i] && b[i]) {
			cntb++;
		}
	}

	if (cnta == 0) {
		cout << -1 << endl;
		return 0;
	}

	int sol = max(cntb / cnta, 1);

	while (sol * cnta <= cntb) {
		sol++;
	}

	cout << sol << endl;

	return 0;
}
