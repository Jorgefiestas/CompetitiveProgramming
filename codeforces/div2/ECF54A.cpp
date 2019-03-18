#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
	for(int i = 0; i<n-1; i++){
		if(str[i]>str[i+1]){
			cout<<str.substr(0,i) + str.substr(i+1,n)<<endl;
			return 0;
		}
	}  
	cout<<str.substr(0,n-1)<<endl;  
	return 0;
}

