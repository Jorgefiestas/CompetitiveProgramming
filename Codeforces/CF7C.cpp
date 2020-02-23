#include <bits/stdc++.h>
using namespace std;

int gcd(long long a, long long b, long long &x, long long &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	long long xt, yt;
	long long g = gcd(b, a%b,xt, yt);
	x = yt;
	y = xt - yt*(a/b);
	return g;
}

int main(){
	long long a, b, c;
	cin>>a>>b>>c;
	long long x, y, g;
	g = gcd(a, b, x ,y);
	if(c%g){cout<<-1<<endl; return 0;}
	long long ct = -c/g;
	x *= ct;
	y *= ct;
	cout<<x<<" "<<y<<endl;
	return 0;
}
