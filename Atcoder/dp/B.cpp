#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, k, h[N], mem[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for (int i = n - 2; i >= 0; i--) {
		mem[i] = INT_MAX;
		for (int j = 1; j <= k; j++) {
			if (i + j >= n) break;
			int a = mem[i + j] + abs(h[i] - h[i + j]);
			mem[i] = min(mem[i], a);
		}
	}

	cout << mem[0] << '\n';
	
	return 0;
}
