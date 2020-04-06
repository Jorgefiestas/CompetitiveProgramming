#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, t;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	bool balanced = true;
	int ubb = INT_MAX, open = 0;
	for (int i = 0; i < n; i++) {
		char c = s[i];

		if (c == '(') {
			open++;
		}
		else {
			open--;
		}

		if (open < 0) {
			balanced = false;
			ubb = min(i, ubb);
		}

		if (!open && !balanced) {
			balanced = true;
			t += (i - ubb + 1);
			ubb = INT_MAX;
		}
	}

	if (open) {
		t = -1;
	}

	cout << t << '\n';
	return 0;
}
