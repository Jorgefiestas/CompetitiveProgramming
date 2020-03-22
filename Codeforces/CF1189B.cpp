#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    long long* mxe = max_element(arr, arr + n);

    long long temp = *mxe;
    *mxe = arr[0];
    arr[0] = temp;

    sort(arr, arr + n, greater<long long>());

    if(arr[0] >= arr[1] + arr[2]){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    cout<<arr[1]<<" "<<arr[0]<<" ";
    for(int i = 2; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
