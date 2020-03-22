#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, h[N], mem[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	mem[n - 2] = abs(h[n - 1] - h[n - 2]);

	for (int i = n - 3; i >= 0; i--) {
		int a1 = mem[i + 1] + abs(h[i] - h[i + 1]);
		int a2 = mem[i + 2] + abs(h[i] - h[i + 2]);
		mem[i] = min(a1, a2);
	}

	cout << mem[0] << '\n';
	
	return 0;
}
