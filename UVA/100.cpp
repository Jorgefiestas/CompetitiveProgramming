#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mem;

int max_cycle(int, int);
int calculate_cycles(int);

int main(int argc, char *argv[]) {
	int i, j;
	mem[1] = 1;
	while(cin>>i>>j)
		cout<<i<<" "<<j<<" "<<max_cycle(i,j)<<endl;
    return 0;
}

int max_cycle(int i, int j){
	int mx= 0;
	for(int x = min(i,j); x<= max(i,j); x++)
		mx =  max(calculate_cycles(x), mx);
	return mx;
}

int calculate_cycles(int x){
	if(mem.find(x) != mem.end()) return mem[x];
	if(x%2 == 0) mem[x] = 1 + calculate_cycles(x/2); 
	else mem[x] = 2 + calculate_cycles((3*x+1)/2);
	return mem[x];
}
