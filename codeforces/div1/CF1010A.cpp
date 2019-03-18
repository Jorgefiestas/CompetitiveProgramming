#include <bits/stdc++.h>
using namespace std;
int n;
double m, a[2001], F[2001], M[2001];

int pos_mod(int x, int y){
	return (y+x%y)%y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	M[0] = m;
	for(int i = 0; i<n; i++)
		cin>>a[2*i+1];
	for(int i = 0; i<n; i++) 
		cin>>a[2*i];
	for(int i = 1; i<=2*n + 1; i++){ 
		F[i] = M[i-1]/(a[pos_mod(1-i, 2*n)] -1);
		if(isinf(F[i])){
			cout<<-1<<endl;
			return 0;
		}
		M[i] = M[i-1] + F[i];
	}
	printf("%.10lf \n",M[2*n] - m);
	return 0;
}
