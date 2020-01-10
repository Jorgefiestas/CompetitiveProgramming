#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int, bool> tn;
vector<int> st;

void generateTri(){
	int t = 1;
	int i = 2;
	while(t <= 1000000000){
		tn[t] = true;
		st.emplace_back(t);
		t = i*(i+1)/2;
		i++;
	}
}
		
int main(){
	cin>>n;
	generateTri();
	for(int i : st){
		if(i>n/2) break;
		if(!tn[n-i]) continue;
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}
