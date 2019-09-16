#include <bits/stdc++.h>
using namespace std;
int k, num[10], permutation[10];
bool inUse[10];   
bool exists;

void per(long long n, int ind){
	if(n > k) return;
	if(ind == 10){
		exists = true;
		return;
	}
	for(int i = 0; i< 10; i++){
		if(inUse[i]) continue;
		inUse[i] = true;
		permutation[ind] = i;
		per(n + num[ind]*i, ind + 1);
		if(exists) return;
		inUse[i] = false;
	}
}

int main(){
	int  t;
	cin>>t;
	
	while(t--){
		memset(inUse, false, sizeof inUse);
		memset(permutation, 0, sizeof permutation);
		exists = false;
		for(int i = 0; i<10; i++)
			cin>>num[i];
		cin>>k;
		per(0, 0);
		if(exists){
			for(int i = 0; i<10; i++)
				cout<<permutation[i]<<" ";
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}
