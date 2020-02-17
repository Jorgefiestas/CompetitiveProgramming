#include <bits/stdc++.h>
using namespace std;
multiset<long long> numerator;
multiset<long long> denominator;
map<long long, vector<long long>> pfact;

void primeFN(long long x){
	if(pfact.find(x) != pfact.end()){
		for(long long y : pfact[x])
			numerator.insert(y);
		return;
	}
	long long ox = x;
	vector<long long> primes;
	while(x%2 == 0){
		numerator.insert(2);
		primes.emplace_back(2);
		x /= 2;
	}
	
	for(long long i = 3; i*i <= x; i += 2){
		while(x%i == 0){
			numerator.insert(i);
			primes.emplace_back(i);
			x /= i;
		}	
	}
	if(x > 2){
		primes.emplace_back(x);
		numerator.insert(x);
	}
	pfact[ox] = primes;
}

void primeFD(long long x){
	if(pfact.find(x) != pfact.end()){
        for(long long y : pfact[x]){
            auto it = numerator.find(y);
			if(it == numerator.end()) denominator.insert(y);
			else numerator.erase(it);
		}
        return;
    }
	long long ox = x;
	vector<long long> primes;
	while(x%2 == 0){
		auto it = numerator.find(2);
		if(it != numerator.end()) numerator.erase(it);
		else denominator.insert(2);
		x /= 2;
		primes.emplace_back(2);
	}

    for(long long i = 3; i*i<=x; i+=2){
        while(x%i == 0){
			auto it = numerator.find(i);
			if(it != numerator.end()) numerator.erase(it);
			else denominator.insert(i);
			x /= i;
			primes.emplace_back(i);
        }
    }
	if(x > 2){
		auto it = numerator.find(x);
		if(it != numerator.end()) numerator.erase(it);
		else denominator.insert(x);
		primes.emplace_back(x);
    }
	pfact[ox] = primes;
}

int main(){
	long long n, m, t;
	cin>>n>>m;
	while(n--){
		cin>>t;
		primeFN(t);
	}
	while(m--){
		cin>>t;
		primeFD(t);
	}
	while(numerator.size() > 100000){
		long long x = *numerator.begin() * *next(numerator.begin(),1);
		numerator.erase(numerator.begin());
		numerator.erase(numerator.begin());
		numerator.insert(x);
	}
	while(denominator.size() > 100000){
		long long x = *denominator.begin() * *next(denominator.begin(),1);
        denominator.erase(denominator.begin());
        denominator.erase(denominator.begin());
        denominator.insert(x);
	}
	if(!numerator.size()) numerator.insert(1);
	if(!denominator.size())denominator.insert(1);

	cout<<numerator.size()<<" "<<denominator.size()<<endl;

	for(long long x : numerator)
		cout<<x<<" ";
	cout<<endl;

	for(long long x : denominator)
		cout<<x<<" ";
	cout<<endl;
}
