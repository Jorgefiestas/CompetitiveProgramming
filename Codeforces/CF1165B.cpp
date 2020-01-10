#include <bits/stdc++.h>
using namespace std;
int n, arr[200000];
int day=1, cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    sort(arr, arr+n);
    for(int i = 0; i<n; i++){
        if(arr[i]  >= day){
            day++;
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
