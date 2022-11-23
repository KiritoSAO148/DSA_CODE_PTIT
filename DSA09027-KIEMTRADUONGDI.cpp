#include <bits/stdc++.h>
using namespace std;

int n,m,s,T;
vector <int> adj[1001];
bool visited[1001];

void dfs(int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]){
			dfs(v);
		}
	}
}

void Path(int s, int t){
	memset(visited,false,sizeof(visited));
	dfs(s);
	if (!visited[t]) cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i=0; i<1001; i++) adj[i].clear();
		cin >> n >> m;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int Q; cin >> Q;
		while (Q--){
			cin >> s >> T;
			Path(s,T);
		}
	}
	return 0;
}
