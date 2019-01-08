#include <iostream>
#include <map>

using namespace std;

int main(){
	int n;
	cin>>n;

	map<int,int> lines;

	for(int i = 0; i<n; i++){
		int m;
		cin>>m;
		for(int i = 0; i<m; i++){
			int line;
			cin>>line;
			lines[line]++;
		}
	}

	for(auto sol : lines){
		if(sol.second == n)
			cout<<sol.first<<' ';
	}

	cout<<endl;
	
	return 0;
}