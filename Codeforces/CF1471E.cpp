#include <bits/stdc++.h>
using namespace std;
int n, rt, k;

int query(int i) {
	int q;
	cout << "? " << i + 1 << endl;
	cin >> q;
	return q;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int rt = sqrt(n) - 1;

	int idx = 0;
	while (query(idx) <= k) {
		idx = (idx + rt) % n;
	}

	idx = (idx + n - 1) % n;
	while (query(idx) != k) {
		idx = (idx + n - 1) % n;
	}

	cout << "! " << idx + 1 << endl;

	return 0;
}
