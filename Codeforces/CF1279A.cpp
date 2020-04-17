#include <bits/stdc++.h>
using namespace std;
int t, c[3];

bool solve() {

	sort(c, c + 3, greater<int>());
	 
	if (c[2] >= c[0] - 1 - c[1]) {
		return true;
	}
	return false;
}

int main() {
	cin >> t;

	while (t--) {
		cin >> c[0] >> c[1] >> c[2];
		if (solve()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}
