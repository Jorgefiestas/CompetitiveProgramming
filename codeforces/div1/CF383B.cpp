#include <bits/stdc++.h>
using namespace std;
stack<char> st;
string tangles;

int main(){
	cin>>tangles;
	for(char x : tangles){
		if(st.empty()) st.push(x);
		else if(x == st.top()) st.pop();
		else st.push(x);
	}
	if(st.empty()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
