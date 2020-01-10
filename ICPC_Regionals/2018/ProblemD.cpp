#include <bits/stdc++.h>
using namespace std;
int n;
set<string> emails;

int main(){
	cin>>n;

	string full;
	for(int i  = 0; i<n; i++){
		cin>>full;
		string domain = full.substr(full.find("@")+1);
		string handle = full.substr(0, full.find("@"));
		string newhandle;

		for(char c : handle){
			if(c == '+') break;
			if(c == '.') continue;
			newhandle += c;
		}

		emails.insert(newhandle+'@'+domain);
	}

	cout<<emails.size()<<endl;

	return 0;
}
