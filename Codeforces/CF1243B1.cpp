#include <bits/stdc++.h>
using namespace std;
int T, n;
string s, t;


void solve(){
	cin >> n >> s >> t;

	int fir, sec;

	int d = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			if(d == 0){
				d++;
				fir = i;
			}
			else if(d == 1){
				d++;
				sec = i;
			}
			else{
				cout << "No" << endl;
				return;
			}
		}
	}

	if(d != 2){
		cout << "No" << endl;
		return;
	}

	char temp = s[fir];
	s[fir] = t[sec];
	t[sec] = temp;

	if(s == t){
		cout << "Yes" << endl;
		return;
	}

	temp = s[fir];
	s[fir] = t[sec];
	t[sec] = temp;
	temp = s[sec];
	s[sec] = t[fir];
	t[fir] = temp;

	if(s == t){
		cout << "Yes" << endl;
		return;
	}

	cout<< "No" << endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while(T--){
		solve();
	}

	return 0;
}
