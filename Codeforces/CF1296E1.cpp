#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, col[N], idx[N];
string str, sorted;
bool res[N];

void impossible() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(col, -1, sizeof col);

	cin >> n >> str;

	sorted = str;
	sort(sorted.begin(), sorted.end());

	for (int i = 0; i < n; i++) {
		idx[i] = i;
	}

	for (int i = 0; i < n; i++) {
		if (str[i] == sorted[i]) continue;

		int j = i;
		while (str[j] != sorted[i]) {
			j += 1;
		}

		if (col[j] == -1) {
			col[j] = (col[i] != -1) ? 1 - col[i] : 0;
		}

		while (j > i) {
			if (col[j - 1] == -1) {
				col[j - 1] = 1 - col[j];
			}
			if (col[j - 1] == col[j]) {
				impossible();
			}
			swap(str[j], str[j - 1]);
			swap(col[j], col[j - 1]);
			swap(idx[j], idx[j - 1]);
			j -= 1;
		}
	}

	for (int i = 0; i < n; i++) {
		res[idx[i]] = !!col[i];
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << res[i];
	}

	return 0;
}
