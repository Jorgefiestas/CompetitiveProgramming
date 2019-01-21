#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);

	vector<vector<bool>> cs(k,vector<bool>(5000,false));
	vector<int> colors(n);
	vector<int> count(k);

	if(k>n){
		cout<<"NO"<<endl;
		return 0;
	}

	int max_c = 0;

	for(int i = 0; i<n; i++){
		int m;
		scanf("%d",&m);
		m--;
		int c = 0;
		while(cs[c][m]){
			c++;
			if(c>=k){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		colors[i] = c;
		cs[c][m] = true;
		count[c]++;
		if(c>max_c) max_c = c;
	}

	int j = 0;
	for(int i = max_c + 1; i<k; i++){
		while(count[colors[j]]==1)
			j++;
		count[colors[j]]--;
		colors[j] = i;
		j++;
	}

	cout<<"YES"<<endl;
	for(int x : colors)
		cout<<x+1<<" ";
	cout<<endl;

	
	return 0;
}