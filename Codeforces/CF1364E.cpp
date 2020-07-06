#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
int n, arr[N], mem[N][N];

int query(int i, int j) {
	if (mem[i][j]) {
		return mem[i][j];
	}
	cout << "? " << i << ' ' << j << endl;
	int qa;
	cin >> qa;
	return mem[i][j] = mem[j][i] = qa;
}


int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.tie(0);
	srand(time(NULL));

	cin >> n;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	shuffle(arr, arr + n, rng);

	int a = arr[0];
	int b = arr[1];
	int pab = query(a, b);

	for (int i = 2; i < n; i++) {
		int c = arr[i];
		int pbc = query(b, c);

		if (pab > pbc) {
			a = c;
			pab = pbc;
		}
		else if (pab == pbc) {
			b = c;
			pab = query(a, b);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == a || i == b) continue;
		if (query(a, i) == query(b, i)) continue;
		ans = (query(a, i) < query(b, i)) ? a : b;
		break;
	}

	arr[ans] = 0;
	for (int i = 1; i <= n; i++) {
		if (i == ans) continue;
		arr[i] = query(ans, i);
	}

	cout << '!';
	for (int i = 1; i <= n; i++) {
		cout << ' ' << arr[i];
	}
	cout << endl;
}
