#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 16) + 10;
int n, a[N], xr[N];

int query(int i, int j) {
	cout << i << ' ' << j << endl;
	int ans;
	cin >> ans;
	return ans;
}

int q_xor(int i, int j) {
	cout << "XOR ";
	return query(i, j);
}

int q_and(int i, int j) {
	cout << "AND ";
	return query(i, j);
}

int q_or(int i, int j) {
	cout << "OR ";
	return query(i, j);
}

void find(int b, int c) {
	int axb = xr[b];
	int axc = xr[c];

	int aab = q_and(1, b);
	int aac, bac;

	if (axb & axc) {
		bac = q_and(b, c);
	}
	else {
		aac = q_and(1, c);
	}

	for (int i = 0; i < 16; i++) {
		if (axb & (1 << i)) {
			if ((axc & (1 << i)) && !(bac & (1 << i))) {
				a[1] |= (1 << i);
			}
			else if (!(axc & (1 << i))) {
				a[1] |= aac & (1 << i);
			}
		}
		else {
			a[1] |= aab & (1 << i);
		}
	}
}

int main() {
	cin >> n;

	int b = -1;
	int c = -1;
	map<int, int> pos;

	for (int i = 2; i <= n; i++) {
		xr[i] = q_xor(1, i);

		if (pos.count(xr[i])) {
			b = pos[xr[i]];
			c = i;
		}
		pos[xr[i]] = i;
	}

	if (b == -1) {
		for (int i = 2; b == -1 && i <= n; i++) {
			for (int j = i + 1; b == -1 && j <= n; j++) {
				if (xr[i] & xr[j]) continue;
				b = i;
				c = j;
			}
		}
	}

	find(b, c);

	for (int i = 2; i <= n; i++) {
		a[i] = xr[i] ^ a[1];
	}

	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;

	return 0;
}
