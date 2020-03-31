#include <bits/stdc++.h>
using namespace std;
int n, m, arr[300005], idx[300005], last[300005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		idx[arr[i]] = i;
		last[i] = -1;
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (idx[a] > idx[b]) {
			swap(a, b);
		}

		last[idx[b]] = max(last[idx[b]], idx[a]);
	}
	
	long long ans = 1;
	for (int i = 1; i < n; i++) {
		last[i] = max(last[i], last[i - 1]);
		ans += i - last[i];
	}

	cout << ans << endl;
	return 0;
}
