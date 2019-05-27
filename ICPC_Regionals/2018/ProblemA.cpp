#include <bits/stdc++.h>
using namespace std;
double fx;
int x;

int gcd(int a, int b){
	if(a%b == 0) return b;
	return gcd(b, a%b);
}

int main(){
	cin>>fx;
	x = (int)(fx*100.0);
	cout<<36000/gcd(36000,x)<<endl;
	return 0;
}
