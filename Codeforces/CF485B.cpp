#include <bits/stdc++.h>
using namespace std;
long long  x[1000], y[1000], s, a, n;

int main(){
	cin>>n;
	for(int i = 0; i<n; i++)
		cin>>x[i]>>y[i];
	s = max(*max_element(x, x+n) - *min_element(x,x+n), *max_element(y, y+n) - *min_element(y,y+n));
	a = s*s;
	cout<<a<<endl;
	return 0;
}
