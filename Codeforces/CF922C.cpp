#include <bits/stdc++.h>
using namespace std;
long long n, k;
unordered_set<long long> rem;

int main(){
	cin>>n>>k;
	if(k > 80){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i = 1; i<=k; i++)
		rem.insert(n%i);
	if(rem.size() == k) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
