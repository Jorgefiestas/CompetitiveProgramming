#include <bits/stdc++.h>
using namespace std;
int t;
long long n, f[1000000];
unordered_map<long long, long long> sf;

long long nof(long long k){
	if(f[k])
		return f[k];

	long long ans = 1;

	long long i = 0;
	for(i = 2; i * i < k; i++){
		if(k % i == 0)
			ans += 2;
	}

	if(i * i == k)
		ans++;

	return f[k] = ans;
}

long long sqrfree_ltk(long long k){
	if(sf.find(k) != sf.end()){
		return sf[k];
	}

	long long ans = 0;

	for(long long i = 2; i*i <= k; i++){
		if(nof(i) & 1){
			ans += k/(i * i);
		}
	}

	return sf[k] = ans;
}

long long solve(){
	cin>>n;

	long long l = 1;
	long long r = 20000000000;
	long long m;

	while(l <= r){
		m = (l + r)/2;
		cout<<l<<" "<<m<<" "<<r<<" "<<sqrfree_ltk(l)<<" "<<sqrfree_ltk(m)<<" "<<sqrfree_ltk(r)<<endl;

		if(sqrfree_ltk(m) < n){
			l = m + 1;
		}
			
		else if(sqrfree_ltk(m) == n){
			if(sqrfree_ltk(m - 1) != n){
				return m;
			}
			r = m - 1;
		}

		else{
			r = m - 1;
		}
	}

	return -1;
}

int main(){
	cin>>t;

	for(int i = 1; i < t; i++){
		cout<<i<<" "<<sqrfree_ltk(i)<<endl;
	}

	/*for(int i = 0; i < t; i++)
		cout<<solve()<<endl;
	*/

	return 0;
}
