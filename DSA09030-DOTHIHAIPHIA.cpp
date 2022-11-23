#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
int color[1001];

bool dfs (int u, int par){
	color[u]=3-color[par];
	for (int v : adj[u]){
		if (color[v]==0){
			if (!dfs(v,u)) return false;
		}
		else if (color[v]==color[u]) return false;
	}
	return true;
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i=0; i<1001; i++) adj[i].clear();
		memset(color,0,sizeof(color));
		color[0]=2;
		cin >> n >> m;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool ok=true;
		for (int i=1; i<=n; i++){
			if (color[i]==0){
				if (!dfs(i,0)){
					ok=false;break;
				}
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
