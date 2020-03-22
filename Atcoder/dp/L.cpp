#include <bits/stdc++.h>
using namespace std;
const int N = 3050;
int n, a[N];
long long mem1[N][N], mem2[N][N];
bool vis1[N][N], vis2[N][N];

long long dpmax(int, int);
long long dpmin(int, int);

long long dpmax(int l, int r) {
	if (l > r) {
		return 0;
	}
	if (vis1[l][r]) {
		return mem1[l][r];
	}
	vis1[l][r] = true;

	long long a1 = a[l] + dpmin(l + 1, r);
	long long a2 = a[r] + dpmin(l, r - 1);
	
	return mem1[l][r] = max(a1, a2);
}

long long dpmin(int l, int r) {
	if (l > r) {
		return 0;
	}
	if (vis2[l][r]) {
		return mem2[l][r];
	}
	vis2[l][r] = true;

	long long a1 = dpmax(l + 1, r) - a[l];
	long long a2 = dpmax(l, r - 1) - a[r];
	
	return mem2[l][r] = min(a1, a2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << dpmax(0, n - 1) << '\n';

	return 0;
}
