#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    int subs = 0;
    while(n>0){
    	int i = 2;
    	bool nisprime = true;
    	for(i; i<=sqrt(n); i++){
    		if(!(n%i)){
    			nisprime = false;
	    		break;
	    	}
    	}
    	if(nisprime){
    		cout<<subs+1<<endl;
    		return 0;
    	}
    	if(i == 2){
    		cout<<subs + n/2<<endl;
    		return 0;
    	}
    	n = n - i;
    	subs++;
    } 
    cout<<subs<<endl;
	return 0;
}
