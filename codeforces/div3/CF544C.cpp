#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> elements(n);
	for(int i = 0; i<n; i++)
		cin>>elements[i];
	sort(elements.begin(), elements.end());
	int maxSize = 0;
	for(auto i = elements.begin(); i<elements.end(); i++){
		int val = *i + 5;
		auto it = upper_bound(i, elements.end(), val) - 1;
		if(distance(i, it)+1 > maxSize) maxSize = distance(i, it)+1;
			};
	cout<<maxSize<<endl;
	return 0;
}
