#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adjList(100005);
char ans[500][100000];

int find(unordered_set<int> &V, int k){
    unordered_set<int> l, r, adjLS, adjRS;
    int SL = 0, SR = 0;

    int lf = *V.begin(), lr;
    l.insert(lf);
    ans[k][lf - 1] = '1';

    for(int u : adjList[lf]){
        if(V.find(u) == V.end()) continue;
        if(r.size() == 0){
            r.insert(u);
            ans[k][u - 1] = '0';
            lr = u;
        }
        else
            adjLS.insert(u);
    }

    if(r.size() == 0){
        for(int v : V){
            for(int u : adjList[v]){
                if(V.find(u) != V.end())
                    return -1;
            }
            ans[k][v - 1] = '0';
        }

        return k;
    }

    for(int u : adjList[lr]){
        if(V.find(u) == V.end()) continue;
        else
            adjRS.insert(u);
    }

    for(int v : V){
        if(v == lf || v == lr) continue;

        bool adjL = (adjLS.find(v) != adjLS.end());
        bool adjR = (adjRS.find(v) != adjRS.end());
        bool JL;

        if(adjL && adjR){
            if(SL >= SR){
                JL = false;
                SR++;
            }
            else{
                JL = true;
                SL++;
            }
        }

        else if(adjL){
            JL = false;
        }

        else if(adjR){
            JL = true;
        }

        else {
            return -1;
        }

        unordered_set<int> adjS;
        if(JL){
            l.insert(v);
            ans[k][v - 1] = '1';
            for(int u : adjList[v]){
                if(V.find(u) == V.end()) continue;
                if(adjLS.find(u) != adjLS.end())
                    adjS.insert(u);
            }
            adjLS = adjS;
        }

        else {
            r.insert(v);
            ans[k][v - 1] = '0';
            for(int u : adjList[v]){
                if(V.find(u) == V.end()) continue;
                if(adjRS.find(u) != adjRS.end())
                    adjS.insert(u);
            }
            adjRS = adjS;
        }
    }

    int optl = find(l, k + 1);
    int optr = find(r, k + 1);

    if(optl == -1 || optr == -1)
        return -1;

    return max(optl, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    int a, b;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        adjList[a].emplace_back(b);
        adjList[b].emplace_back(a);
    }

    unordered_set<int> V(n);
    for(int i = 1; i <= n; i++)
        V.insert(i);

    int r = find(V, 0);
    cout<<r<<endl;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] == '\0')
                ans[i][j] = '0';
            cout<<ans[i][j];
        }
        cout<<endl;
    }


    return 0;
}
