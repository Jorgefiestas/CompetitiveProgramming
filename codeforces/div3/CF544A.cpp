#include <bits/stdc++.h>
using namespace std;

int main(){
	int h1, m1, h2, m2;
	scanf("%d:%d",&h1,&m1);
	scanf("%d:%d",&h2,&m2);
	int ah1 = h1*60+m1;
	int ah2 = h2*60+m2;
	int ahm = ah1 + ah2;
	ahm /= 2;
	int hf = ahm/60;
	int mf = ahm%60;
	if(hf<10) cout<<'0';
	cout<<hf<<':';
	if(mf<10) cout<<'0';
	cout<<mf<<endl;
	return 0;
}
