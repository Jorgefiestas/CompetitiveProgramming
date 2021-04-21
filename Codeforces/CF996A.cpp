#include <bits/stdc++.h>
using namespace std;
const int val[] = {100, 20, 10, 5, 1};
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int ans = 0;
	for (int v : val) {
		ans += n / v;
		n = n % v;
	}

	cout << ans << '\n';

	return 0;
}
