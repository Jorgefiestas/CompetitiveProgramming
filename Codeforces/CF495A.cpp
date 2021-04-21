#include <bits/stdc++.h>
using namespace std;
int n;
const int cnt[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << cnt[n % 10] * cnt[n / 10] << '\n';

	return 0;
}
