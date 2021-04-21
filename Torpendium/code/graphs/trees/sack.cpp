int sz[N]

void calSize(int v, int p) {
	sz[v] = 1;
 
	for (int u : adjList[v]) {
		if (u == p) continue;
		calSize(u, v);
		sz[v] += sz[u];
	}
}
 
int timer, st[N + 5], ft[N + 5], ver[N + 5];

void dfs(int v, int p, bool keep){
	ver[timer] = v;
	st[v] = timer++;
 
    int bigChild =  -1;
 
    for (int u : adjList[v]) {
       if (u == p) continue;
	   
	   bigChild = (bigChild != -1 && sz[bigChild] > sz[u]) ? bigChild : u;
	}
 
    for (int u : adjList[v]) {
        if(u == p || u == bigChild) continue;
		dfs(u, v, 0); 
	}
 
    if(bigChild != -1) {
        dfs(bigChild, v, 1);
	}

	ft[v] = timer;
 
    for(auto u : adjList[v]) {
		if(u == p || u == bigChild) continue;
 
	    for(int i = st[u]; i < ft[u]; i++) {
			int w = ver[i];
			// Add w to tree
		}
	}
 
 
	// Add v to tree and query
 
    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
			//Remove ver[i]
		}
	}
}
