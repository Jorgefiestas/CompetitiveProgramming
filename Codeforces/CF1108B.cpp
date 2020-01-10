#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	scanf("%d",&n);

	vector<int> divisors(n);

	for(int i = 0; i<n; i++)
		cin>>divisors[i];
	sort(divisors.begin(),divisors.end());

	int v1 = divisors[n-1];
	int v2;
	int temp = v1;
	int last = 0;


	if(divisors[n-2]==v1){
		cout<<v1<<" "<<v1<<endl;
		return 0;
	}

	for(int i = n-1; i>=0; i--){
		if(temp%divisors[i] || divisors[i] == last){
			v2 = divisors[i];
			break;
		}
		last  = divisors[i];
	}

	cout<<v1<<" "<<v2<<endl;

	return 0;
}
