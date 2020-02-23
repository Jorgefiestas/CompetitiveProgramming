#include <bits/stdc++.h>
using namespace std;
int t, a, b, p, n;
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> a >> b >> p;
		cin >> str;

		n = str.size();

		str[n - 1] = 'C';
		int m = 0;
		int i;

		for (i = n - 2; i >= 0; i--) {
			if (str[i] == str[i + 1]) continue;
			
			if (str[i] == 'A') {
				m += a;
			}
			else {
				m += b;
			}

			if (m > p) {
				break;
			}
		}

		cout << i + 2 << '\n';
	}

	return 0;
}
