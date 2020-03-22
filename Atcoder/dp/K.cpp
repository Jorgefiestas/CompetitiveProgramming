#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, k, a[105];
bool mem[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= k; i++) {
		mem[i] = false;
		for (int j = 0; j < n; j++) {
			int x = a[j];

			if (i - x >= 0 && !mem[i - x]) {
				mem[i] = true;
			}
		}
	}

	if (mem[k]) {
		cout << "First\n";
	}
	else {
		cout << "Second\n";
	}

	return 0;
}
