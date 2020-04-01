#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, a[N][N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int xr = 0;
	for (int i = 0; i < n; i++) {
		xr = xr ^ a[i][0];
	}

	int dr = 0, dc = 0;

	if (!xr) {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) 
				if (a[i][j] != a[i][0]) {
					dr = i;
					dc = j;
				}
		}
		if (!dr && !dc) {
			cout << "NIE\n";
			return 0;
		}
	}

	cout << "TAK\n";

	for (int i = 0; i < n; i++) {
		if (i == dr) {
			cout << dc + 1 << ' ' ;
		}
		else {
			cout << 1 << ' ' ;
		}
	}
	cout << '\n';

	return 0;
}
