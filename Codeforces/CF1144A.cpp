#include <bits/stdc++.h>
using namespace std;
int n;
string word;

bool solve(){
	sort(word.begin(), word.end());
	char t = word[0];
	for(int i = 1; i<word.size(); i++){
		if(word[i] != t+1) return false;
		t = word[i];
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>word;
		if(solve()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
