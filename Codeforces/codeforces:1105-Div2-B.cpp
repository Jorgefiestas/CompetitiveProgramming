#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	int n, k;
	scanf("%d %d", &n, &k);
	string str;
	cin>>str;

	map<char, int> count;

	char curr = '0';
	int temp = 1;

	for(int i =0; i<n; i++){
		if(curr == str[i]){
			temp++;
		}
		else{
			count[curr] += temp/k;
			curr = str[i];
			temp = 1;
		}
	}

	count[curr] += temp/k;

	int max = 0;

	for(char c ='a'; c<='z';c++){
		if(count[c]>max)
			max = count[c];
	}

	cout<<max<<endl;

	return 0;
}