#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int B = 10;
int n, mn[N]; 

vector<int> query(vector<int> &idx) {
	cout << idx.size() << endl;
	for (int x : idx) {
		cout << x << ' ';
	}
	cout << endl;

	vector<int> ans(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> ans[i];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		mn[i] = INT_MAX;
	}

	for (int j = B - 1; j >= 0; j--) {
		if ((1 << j) >= n) continue;

		vector<int> q1, q2;
		for (int i = 1; i <= n; i++) {
			if (i & (1 << j)) {
				q1.emplace_back(i);
			}
			else {
				q2.emplace_back(i);
			}
		}

		vector<int> a1, a2;
		a1 = query(q1);
		a2 = query(q2);

		for (int i = 1; i <= n; i++) {
			if (i & (1 << j)) {
				mn[i] = min(mn[i], a2[i]);
			}
			else {
				mn[i] = min(mn[i], a1[i]);
			}
		}
	}
	
	cout << -1 << endl;
	for (int i = 1; i <= n; i++) {
		cout << mn[i] << ' ';
	}
	cout << endl;


	return 0;
}
