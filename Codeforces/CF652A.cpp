#include <bits/stdc++.h>
using namespace std;
int h1, h2, a, b;
 
int main(){
	cin >> h1 >> h2 >> a >> b;
 
	if (b >= a && h2 - h1 > a*8) {
		cout << -1 << endl;
		return 0;
	}
 
	h1 += a*8;	
	int d = (a - b) * 12;
	int ans = 0;
 
	while (h1 < h2){
		ans++;
		h1 += d;
	}
 
	cout << ans << endl;
 
	return 0;
}
