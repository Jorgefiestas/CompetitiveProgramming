#include <bits/stdc++.h>
#define PI 3.14159265358979323846264338327950288419716939937510
using namespace std;
int n;
vector<long double> coor;

long double mod(long double x, long double y){
	return sqrt(x*x + y*y);
}

long double arg(long double x, long double y){
	long double res  = atan2(y,x)* 180.0 / PI;
	if(res<0) return 360.0 + res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++){
		long double x, y;
		cin>>x>>y;
		coor.push_back(arg(x, y));
	}
	sort(coor.begin(), coor.end());
	coor.push_back(360 + coor[0]);
	long double mx = 0;
	for(int i = 0; i<coor.size()-1; i++)
		if(coor[i+1] - coor[i] > mx)  mx = coor[i+1] - coor[i];
	printf("%.10Lf \n", 360 - mx);
	return 0;
}
