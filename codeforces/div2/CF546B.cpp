#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, p;
	cin>>m>>p;
	p = min(p-1, m-p);
	cout<<3*m + p<<endl;
	return 0;
}
