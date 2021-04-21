#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 100;
int n, p[N];

int query(int i, int j) {
	int ans;

	cout << "? " << i << ' ' << j << endl;
	cin >> ans;
	return ans;
}

int main() {
	cin >> n;

	if (n == 1) {
		cout << "! 1" << endl;
		return 0;
	}


	int last = 1;

	for (int i = 2; i <= n; i++) {
		int q1 = query(i, last);
		int q2 = query(last, i);
		
		if (q1 > q2) {
			p[i] = q1;
		}
		else {
			p[last] = q2;
			last = i;
		}
	}

	p[last] = n;

	cout << '!';
	for (int i = 1; i <= n; i++) {
		cout << ' ' << p[i];
	}
	cout << endl;

	return 0;
}
