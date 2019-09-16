#include <bits/stdc++.h>
using namespace std;
int n, temp, cnt[200005], mem[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>temp, cnt[temp]++;
    
    for(int i = 1; i<200005; i++){
        if(cnt[i-1]>1) mem[i] = mem[i-1] + cnt[i];
        else mem[i] = cnt[i-1]+cnt[i];
    }

    deque<int> q;
    int max = (int)(max_element(mem, mem+200005) - mem);
    temp = max;

    for(int i = 0; i<mem[max]; i++){
        if(i%2) q.push_back(temp);
        else q.push_front(temp);
        cnt[temp]--;
        if(!cnt[temp]) temp--;
    }

    cout<<q.size()<<endl;
    while(!q.empty())
        cout<<q.front()<<" ", q.pop_front();
    cout<<endl;
}
