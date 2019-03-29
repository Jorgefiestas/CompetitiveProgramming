#include <bits/stdc++.h>
using namespace std;
int n;
long long z, cnt;
string bra;
unordered_map<long long, long long> toOpen, toClose;

void toc(int i){
	cin>>bra;
	long long  o = 0, c = 0;
	for(char ch : bra){
		if(ch == '('){
			o++;
		}
		else{
			if(o == 0) c++;
			else o--;
		}
	}
	if(o && c) return;
	if(c) toClose[c]++;
	else if(o) toOpen[o]++;
	else z++;
}

int main(){
	cin>>n;
	for(int i = 0; i<n; i++)
		toc(i);
	for(auto it : toOpen){
		if(toClose.find(it.first) == toClose.end()) continue;
		cnt += it.second*toClose[it.first];
	}
	cnt += z*z;
	cout<<cnt<<endl;
	return 0;
}
