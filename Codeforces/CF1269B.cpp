#include <bits/stdc++.h>
using namespace std;
int n, m, x = INT_MAX, a[2000], b[2000];

void comp(int idx) {
	multiset<int> inB;
	for (int i = 0; i < n; i++) {
		inB.insert(b[i]);
	}

	int tx = (m + (b[idx] - a[0])) % m;

	for (int i = 0; i < n; i++) {
		auto it = inB.find((a[i] + tx) % m);
		if (it == inB.end()) {
			return;
		}
		inB.erase(it);
	}

	x = min(x, tx);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		comp(i);
	}

	cout << x << endl;

	return 0;
}
