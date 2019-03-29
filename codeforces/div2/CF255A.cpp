#include <bits/stdc++.h>
using namespace std;
int n, cnt[3];

int main(){
	cin>>n;
	for(int i = 0; i<n; i++){
		int t;
		cin>>t;
		cnt[i%3] += t;
	}
	int m = 0;
	for(int i = 1; i<3; i++)
		if(cnt[i] > cnt[m]) m = i;
	if(m == 0)
		cout<<"chest"<<endl;
	else if(m == 1)
		cout<<"biceps"<<endl;
	else
		cout<<"back"<<endl;
	return 0;
}
