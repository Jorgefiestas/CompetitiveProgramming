#include <bits/stdc++.h>
using namespace std;
int t, pc, pr;

int digits(int p) {
	return (p + 8) / 9;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> pc >> pr;
		int cd = digits(pc);
		int rd = digits(pr);

		cout << (cd >= rd) << ' ' << min(cd, rd) << '\n';
	}

	return 0;
}
