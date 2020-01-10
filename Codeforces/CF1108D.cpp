#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	string lamps;
	cin>>lamps;

	int mem[n][3];
	int parent[n][3];
	string pos = "RGB";

	for(int i = 0; i<3; i++){
		if(lamps[n-1] == pos[i]) mem[n-1][i] = 0;
		else mem[n-1][i] = 1;
	}

	for(int x = n-2; x>=0; x--){
		for(int c = 0; c<3; c++){
			if(lamps[x] == pos[c]) mem[x][c] = 0;
			else mem[x][c] = 1;
			int min = INT_MAX;
			int dad = 0;
			for(int y = 0; y<3; y++){
				if(y == c) continue;
				if(mem[x+1][y]<min){
					min = mem[x+1][y];
					dad = y;
				}
			}
			parent[x][c] = dad;
			mem[x][c] += min;
		}
	}


	int y = 0;

	for(int i = 1; i<3; i++)
		if(mem[0][i]<mem[0][y]) y = i;

	cout<<mem[0][y]<<endl;
	cout<<pos[y];

	for(int i = 0; i<n-1; i++){
		y = parent[i][y];
		cout<<pos[y];
	}

	cout<<endl;

	return 0;
}
