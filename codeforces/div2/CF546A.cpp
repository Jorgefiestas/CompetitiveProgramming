#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> chap(n);
	for(int i = 0; i<n; i++){
		int l, r;
		cin>>l>>r;
		chap[i] = r;
	}
	int k;
	cin>>k;
	auto it = lower_bound(chap.begin(), chap.end(), k);
	cout<<distance(it,chap.end())<<endl;
	return 0;
}
