#include <bits/stdc++.h>
using namespace std;
int q, n, arr[300000];

int solve(){
    cin>>n;
    int ans = 0;
    set<int> temp;

    int t;
    for(int i = 0; i<n; i++){
        cin>>t;
        temp.insert(t);
    }

    int idx = 1;
    n = temp.size();
    for(int x : temp){
        arr[n - idx] = x;
        idx++;
    }

    if(n == 1){
        return arr[0];
    }

    
    for(int s = 0; s < 2; s++){
        int i = s + 1;

        while(i < n && arr[s]%arr[i] == 0) i++;

        if(i >= n){
            ans = max(ans, arr[s]);
            continue;
        }

        int j = i + 1;

        while(j < n && (arr[s]%arr[j] == 0 || arr[i]%arr[j] == 0)) j++;

        if(j >= n){
            ans = max(ans, arr[s] + arr[i]);
            continue;
        }
        ans = max(ans, arr[i] + arr[j] + arr[s]);
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int i = 0; i < q; i++)
        cout<<solve()<<endl;

    return 0;
}
