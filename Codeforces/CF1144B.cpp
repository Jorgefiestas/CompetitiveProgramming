#include <bits/stdc++.h>
using namespace std;
int n, temp, sm;
vector<int> even, odd;

void op(vector<int> &a, vector<int> &b){
	for(int i = a.size()+1; i<b.size(); i++)
		sm += b[i];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>temp;
		if(temp%2) odd.emplace_back(temp);
		else even.emplace_back(temp);
	}
	sort(odd.begin(), odd.end(), greater<int>());
	sort(even.begin(), even.end(), greater<int>());
	op(even, odd);
	op(odd, even);
	cout<<sm<<endl;
	return 0;
}
