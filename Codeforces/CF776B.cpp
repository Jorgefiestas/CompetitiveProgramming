#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, color[N];

int main() {
	cin >> n;

	for (int i = 2; i <= n + 3; i++) {
		color[i] = 1;
	}

	for (int i = 2; i <= n + 1; i++) {
		if (color[i] != 1) continue;
		for (int j = 2 * i; j <= n + 1; j += i) {
			if (color[j] == color[i]) {
				color[j]++;
			}
		}
	}

	cout << *max_element(color + 2, color + n + 2) << '\n';
	for (int i = 2; i <= n + 1; i++) {
		cout << color[i] << ' ';
	}
	cout << '\n';

	return 0;
}
