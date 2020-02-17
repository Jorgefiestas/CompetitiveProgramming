#include <bits/stdc++.h>
using namespace std;
bool notPrimes[1000001];

int main(){
	notPrimes[1] = true;
	for(long long i  = 2; i<=1000; i++){
		for(long long j = i*i; j<= 1000000; j+= i){
			notPrimes[j] = true;
		}
	}
	long long n;
	long long x;
	cin>>n;
	while(n--){
		cin>>x;
		long long sq = sqrt(x);
		if(sqrt(x) != sq) cout<<"NO"<<endl;
		else if(!notPrimes[sq]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
