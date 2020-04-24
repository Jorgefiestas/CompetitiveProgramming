#include <bits/stdc++.h>
using namespace std;
string n;

int main() {
	cin >> n;

	int ans = (int) pow(9, n.size() - 1);
	int mul = 1;
	for (int i = 0; i < n.size(); i++) {
		for (int j = 1; j < n[i] - '0'; j++) {
			ans = max(ans,  mul * j * (int) pow(9, n.size() - i - 1));
		}
		mul *= (n[i] - '0');
	}
	ans = max(ans, mul);

	cout << ans << endl;

	return 0;
}
