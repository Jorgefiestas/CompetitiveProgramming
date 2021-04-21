#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;

	int c1 = a + b + c;
	int c2 = 2 * (a + c);
	int c3 = 2 * (b + c);
	int c4 = 2 * (a + b);
	cout << min({c1, c2, c3, c4}) << '\n';

	return 0;
}
