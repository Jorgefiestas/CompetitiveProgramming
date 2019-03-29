#include <bits/stdc++.h>
using namespace std;
long long h, w, c;

int main(){
	cin>>w>>h;
	for(long long i = 1; i<h; i++)
		for(long long j = 1; j<w; j++)
			c += min(j, w-j)*min(i, h-i);
	cout<<c<<endl;
	return 0;
}
