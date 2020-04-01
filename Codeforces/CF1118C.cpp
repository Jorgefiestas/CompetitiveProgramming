#include <bits/stdc++.h>
using namespace std;
int n,one, two, c, mat[20][20];
unordered_map<int, int> cnt;
vector<int> cl;

int fal(){
	cout<<"NO"<<endl;
	return 0;
}

int main(){
	cin>>n;
	for(int i = 0; i<n*n; i++){
		int t;
		cin>>t;
		cnt[t]++;
	}
	int i = 0, j = 0;
	for(auto it : cnt){
		while(it.second >= 4){
			if(i == n/2) break;
			mat[i][j] = it.first;
			mat[n-i-1][j] = it.first;
			mat[i][n-j-1] = it.first;
			mat[n-i-1][n-j-1] = it.first;
			j++;
			if(j == n/2){
				i++;
				j = 0;
			}
			it.second -= 4;
		}
		if(it.second && it.second <= 3 && n%2 == 0)return fal();
		while(it.second >= 2){
			cl.emplace_back(it.first);
			it.second -= 2;
		}
		if(it.second){
			if(c) return fal();
			c = it.first;
		}
	}
	if(n%2){
		if(cl.size() != n-1) return fal();
		int idx = 0;
		for(int i = 0; i<n/2; i++){
			mat[n/2][i] = cl[idx];
			mat[n/2][n-1-i] = cl[idx];
			idx++;
		}
		for(int i = 0; i<n/2; i++){
			mat[i][n/2] = cl[idx];
			mat[n-1-i][n/2] = cl[idx];
			idx++;
		}
		mat[n/2][n/2] = c;
	}
	cout<<"YES"<<endl;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
