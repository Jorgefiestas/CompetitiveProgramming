#include <bits/stdc++.h>
using namespace std;
int n;
long long x, y;

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		if (x - y == 1) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
		}
	}

	return 0;
}
