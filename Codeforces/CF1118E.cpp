#include <bits/stdc++.h>
using namespace std;
long long n, k, idx[200005];
vector<pair<int, int>> p;

int fal(){
	cout<<"NO"<<endl;
	return 0;
}

int main(){
	cin>>n>>k;
	if(k*(k-1)<n) return fal();
	for(int i = 0; i<k; i++)
		idx[i] = (i+1)%k;
	for(int i = 0; i< n; i++){
		if(idx[i%k] == i%k) idx[i%k] = (idx[i%k] + 1)%k;
		p.push_back(make_pair(i%k + 1, idx[i%k] + 1));
		idx[i%k] = (idx[i%k] + 1)%k;
	}
	cout<<"YES"<<endl;
	for(pair<int, int> pa : p)
		cout<<pa.first<<" "<<pa.second<<endl;
	return 0;
}
