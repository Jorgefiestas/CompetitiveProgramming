#include <bits/stdc++.h>
using namespace std;
int T, n, temp, arr[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0; i < 3; i++)
            arr[i] = 0;
        for(int i = 0; i < n; i++){
            cin>>temp;
            arr[temp%3]++;
        }
        int mn = min(arr[1], arr[2]);
        int sol = arr[0] + mn;
        sol += (n - arr[0] - 2*mn)/3;
        cout<<sol<<endl;
    }
    return 0;
}
