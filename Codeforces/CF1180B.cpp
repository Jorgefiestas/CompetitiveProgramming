#include <bits/stdc++.h>
using namespace std;
int n, mn, arr[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    mn = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] >= 0){
            arr[i] = -arr[i] - 1;
        }
        if(arr[i] < arr[mn])
            mn = i;
    }

    if(n%2){
        arr[mn] = -arr[mn] - 1;
    }

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    return 0;
}
