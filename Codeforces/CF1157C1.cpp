#include <bits/stdc++.h>
using namespace std;
int n, arr[200005];
vector<int> ordered;
string ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int i = 0, j = n-1, x = 0;
    if(arr[i] < arr[j]){
        ordered.emplace_back(arr[i]);
        ans += 'L';
        i++;
    }
    else{
        ordered.emplace_back(arr[j]);
        ans += 'R';
        j--;
    }
    while(i<j){
        if(arr[i] <= ordered[x] && arr[j] <= ordered[x])
            break;
        if(arr[i] > ordered[x] && arr[j] > ordered[x]){
            if(arr[i] < arr[j]){
                ordered.emplace_back(arr[i]);
                ans += 'L';
                i++;
            }
            else{
                ordered.emplace_back(arr[j]);
                ans += 'R';
                j--;
            }
        }
        else if(arr[i] > ordered[x]){
            ordered.emplace_back(arr[i]);
            ans += 'L';
            i++;
        }
        else{
            ordered.emplace_back(arr[j]);
            ans += 'R';
            j--;
        }
        x++;
    }
    if(i == j && arr[i] > ordered[x]){
        x++;
        ans += 'R';
    }

    cout<<x+1<<endl;
    cout<<ans<<endl;
    return 0;
}
