#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	if(!(a%b)) return b;
	else return gcd(b, a%b);
}

int main(){
	int t;
	long long a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		long long g = gcd(a, b);
		cout<<g<<" "<<a*b/g<<endl;
	}
}
