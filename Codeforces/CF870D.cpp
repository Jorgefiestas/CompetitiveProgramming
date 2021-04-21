#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N], b[N];

int query(int i, int j) {
	cout << "? " << i << ' ' << j << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int q = query(i, 0);
	}

	for (int i = 0; i < n; i++) {
		int q = query(0, i);
	}

	return 0;
}
