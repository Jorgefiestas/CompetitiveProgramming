#include <bits/stdc++.h>
using namespace std;
int x, y;
char p;

int gcd(int a, int b){
	if(a%b == 0) return b;
	return gcd(b, a%b);
}

int main(){
	cin>>x>>p>>y;
	x = x * 100 + y;
	cout<<36000/gcd(36000,x)<<endl;
	return 0;
}
