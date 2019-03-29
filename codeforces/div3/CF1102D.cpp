#include <bits/stdc++.h>
using namespace std;
int n, cnt[3];
string str;

int main(){
	cin>>n>>str;
	for(char c : str)
		cnt[c-'0']++;
	for(int i = 0; i<n; i++){
		if(cnt[0] >= n/3) break;
		if(cnt[str[i]-'0'] <= n/3)continue;
		cnt[str[i]-'0']--;
		str[i] = '0';
		cnt[0]++;
	}
	for(int i = n-1; i>=0; i--){
		if(cnt[2] >= n/3) break;
		if(cnt[str[i]-'0'] <= n/3)continue;
		cnt[str[i]-'0']--;
		str[i] = '2';
		cnt[2]++;
	}
	if(cnt[0] > n/3){
		for(int i = n-1; i>=0; i--){
			if(cnt[1] == n/3) break;
			if(cnt[str[i]-'0'] <= n/3) continue;
			cnt[str[i]-'0']--;
			str[i] = '1';
			cnt[1]++;
		}
	}	
	else{
		for(int i = 0; i<n; i++){
			if(cnt[1] == n/3) break;
			if(cnt[str[i]-'0'] <= n/3) continue;
			cnt[str[i]-'0']--;
			str[i] = '1';
			cnt[1]++;
		}
	}
	cout<<str<<endl;
	return 0;
}
