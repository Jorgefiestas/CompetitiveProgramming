#include <bits/stdc++.h>
using namespace std;
int n, m, l[200005], r[2000005];
string s, t;


int main(){
    cin>>s>>t;
    n = s.size();
    m = t.size();

    int j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == t[j]){
            l[j] = i;
            j++;
        }
        if(j == m ) break;
    }

    j = m - 1;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == t[j]){
            r[j] = i;
            j--;
        }
        if(j == - 1) break;
    }

    
    int ans = r[0];
    for(int le = 1; le < m; le++){
        ans = max(ans, r[le] - l[le - 1] - 1);
    }

    ans = max(ans, n - l[m - 1] - 1);

    cout<<ans<<endl;
    return 0;
}
