#include <bits/stdc++.h>
using namespace std;
int t, n, s, arr[100000];

int solve() {
	int mx = 0;
	int cs = 0;

	for (int i = 0; i < n; i++) {
		cs += arr[i];
		mx = (arr[i] > arr[mx]) ? i : mx;
		if (cs > s) {
			return mx + 1;
		}
	}
	return 0;
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> s;
		for(int i = 0; i < n; i ++) {
			cin >> arr[i];
		}

		cout << solve() << endl;
	}

	return 0;
}
