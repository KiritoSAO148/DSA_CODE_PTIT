#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

bool dfs (int u, int par){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]){
			if (dfs(v,u)) return true;
		}
		else if (v!=par) return true;
	}
	return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i=0; i<1001; i++) adj[i].clear();
		memset(visited,false,sizeof(visited));
		cin >> n >> m;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool ok=false;
		for (int i=1; i<=n; i++){
			if (!visited[i] && dfs(i,0)){
				ok=true;break;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
