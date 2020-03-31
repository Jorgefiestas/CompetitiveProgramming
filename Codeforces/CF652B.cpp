#include <bits/stdc++.h>
using namespace std;
int n, arr[1005], res[1005];

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n/2; i++) {
		res[2*i] = arr[i];
		res[2*i + 1] = arr[n - 1 - i];
	}
	if (n & 1) {
		res[n - 1] = arr[n/2];
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}
