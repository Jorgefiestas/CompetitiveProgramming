#include <bits/stdc++.h>
using namespace std;
int a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	bool neg = false;
	if (a < b) {
		swap(a, b);
		neg = true;
	}

	vector<int> ans;
	int sum = 0;

	for (int i = 1; i <= a; i++) {
		ans.push_back(i);
		sum += i;
	}

	for (int i = 1; i < b; i++) {
		ans.push_back(-i);
		sum -= i;
	}

	ans.push_back(-sum);

	for (int x : ans) {
		cout << (neg ? -x : x) << ' ';
	}
	cout << '\n';

	return 0;
}
