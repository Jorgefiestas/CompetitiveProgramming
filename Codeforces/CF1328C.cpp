#include <bits/stdc++.h>
using namespace std;
int t, n;
string c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> c;
		string a(n, ' '), b(n, ' ');

		bool eq = true;
		for (int i = 0; i < n; i++) {
			switch (c[i]) {
				case '0':
					if (i == 0)  {
						a[i] = '2';
						b[i] = '1';
						eq = false;
					}
					else {
						a[i] = '0';
						b[i] = '0';
					}
					break;
				case '1':
					if (eq) {
						a[i] = '1';
						b[i] = '0';
						eq = false;
					}
					else {
						a[i] = '0';
						b[i] = '1';
					}
					break;
				case '2':
					if (eq) {
						a[i] = '1';
						b[i] = '1';
					}
					else {
						a[i] = '0';
						b[i] = '2';
					}
					break;
			}
		}

		cout << a << '\n' << b << '\n';
	}

	return 0;
}
