#include <bits/stdc++.h>
using namespace std;
int n, t;
map<int, int> cnt;
vector<int> a, b;

int imp(){
	cout<<"NO"<<endl;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)
		cin>>t, cnt[t]++;
	for(auto it : cnt){
		a.emplace_back(it.first);
		if(it.second == 2) b.emplace_back(it.first);
		if(it.second > 2) return imp();
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	cout<<"YES"<<endl;
	cout<<a.size()<<endl;
	for(int x : a)
		cout<<x<<" ";
	cout<<endl;
	cout<<b.size()<<endl;
	for(int x : b)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
