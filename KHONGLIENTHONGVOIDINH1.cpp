#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[301];
bool visited[301];

void dfs (int u){
	visited[u] = true;
	for (int v : adj[u]){
		if (!visited[v]) dfs(v);
	}
}

int main(){
    cin >> n >> m;
    f0 (i,m){
    	int x, y; cin >> x >> y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    dfs(1);
    int ok = 0;
    for (int i = 1; i <= n; ++i){
    	if (!visited[i]){
    		ok = 1;
    		cout << i << '\n';
    	}
    }
    if (!ok) cout << 0;
    return 0;
}
