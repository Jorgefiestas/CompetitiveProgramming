#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, col[N], mx[26];
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> str;

	for (int i = n - 1; i >= 0; i--) {
		int c = str[i] - 'a';

		int mxc = 0;
		for (int j = 0; j < c; j++) {
			mxc = max(mxc, mx[j]);
		}
		col[i] = mxc + 1;
		mx[c] = col[i];
	}

	cout << *max_element(mx, mx + 26) << '\n';
	
	for (int i = 0; i < n; i++) {
		cout << col[i] << ' ';
	}
	cout << '\n';

	return 0;
}
