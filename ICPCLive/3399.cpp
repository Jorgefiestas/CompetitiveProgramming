#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bool isPrime[10001];
unordered_map<int, int> mem;
int n;

void sieve(){
	for(int j = 2; j <= 100; j++){
		if(isPrime[j]) continue;
		for(int i = j*j; i<=10000; i += j)
			isPrime[i] = true;
	}

	isPrime[0] = true;
	isPrime[1] = true;
	for(int i = 2; i <= 10000; i++)
		if(!isPrime[i]) primes.emplace_back(i);
}

int calc(int x){
	int s = 0, w = 0;
	int curr = primes[0];
	for(int i = 1; i<=primes.size(); i++){
		while(curr > x) curr -= primes[s++];
		if(curr == x) 
			w++;
		if(primes[i] > x) break;
		curr += primes[i];
	}
	return w;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	cin>>n;
	while(n){
		cout<<calc(n)<<endl;
		cin>>n;
	}
	return 0;
}
