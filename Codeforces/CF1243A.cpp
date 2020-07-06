
#include <bits/stdc++.h>
using namespace std;
int T, n, arr[1005];

int main(){
	cin >> T;

	while(T--){
		cin >> n;

		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		sort(arr, arr + n, greater<int>());

		int a = 0;

		for(int i = 1; i <= n; i++){
			int ta = min(i, arr[i - 1]);
			a = max(a, ta);
		}

		cout << a << endl;
	}

	return 0;
}
