#include <bits/stdc++.h>
using namespace std;
int t;
string n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		reverse(n.begin(), n.end());
		vector<int> ans;

		int d = 1;
		for (char c : n) {
			int dig = (int) (c - '0') * d;
			if (dig) {
				ans.emplace_back(dig);
			}
			d *= 10;
		}

		cout << ans.size() << '\n';
		for (int dig : ans) {
			cout << dig << ' ';
		}
		cout << '\n';
	}
}
