#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n, m, total, arr[200001];
vector<PII> sales;
unordered_map<int, bool> mem;

bool check_day(int d){
    if(mem.find(d) != mem.end()) return mem[d];
    int last[200001] = {-1};
    int buy[200001] = {0};

    for(PII p : sales){
        if(p.first > d || last[p.second] > p.first) continue;
        last[p.second] = p.first;
    }

    unordered_map<int, vector<int>> sl;
    for(int i = 0; i<n; i++)
        if(last[i] != -1) sl[last[i]].emplace_back(i);

    int cnt = 0;
    for(int i = 1; i<= d; i++){
        cnt++;
        for(int t : sl[i]){
            if(arr[t] - buy[t] > cnt){
                buy[t] += cnt;
                cnt = 0;
            }
            else{
                cnt -= (arr[t] - buy[t]);
                buy[t] = arr[t];
            }
        }
    }

    for(int i = 0; i<n; i++){
        int left = arr[i] - buy[i];
        if(2*left > cnt) return mem[d] = false;
        cnt -= 2*left;
    }

    return mem[d] = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        total += arr[i];
    }
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        sales.push_back(make_pair(a,b-1));
    }

    int l = 1, r = 2*total;
    int m;
    
    while(true){
        m = (l+r)/2;
        if(check_day(m)){
            if(m == 1 || !check_day(m-1)) break;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }

    cout<<m<<endl;
    return 0;
}
