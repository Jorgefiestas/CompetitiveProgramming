#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	string lamps;
	cin>>lamps;

	vector<string> pos(6);

	string arr[6] = {"RGB","RBG","BRG","BGR","GRB","GBR"};
	int min_p = 0;
	int min = INT_MAX;

	for(int i = 0; i<6; i++){
		int cost = 0;
		for(int j = 0; j<n; j++)
			if(lamps[j] != arr[i][j%3]) cost ++;
		if(cost<min){
			min = cost;
			min_p = i;
		}
	}

	cout<<min<<endl;

	for(int i = 0; i<n; i++){
		cout<<arr[min_p][i%3];
	}
	cout<<endl;

	return 0;
}
