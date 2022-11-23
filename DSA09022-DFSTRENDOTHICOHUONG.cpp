#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void dfs(int u){
	visited[u]=true;
	cout << u << " ";
	for (int v : adj[u]){
		if (!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		memset(visited,false,sizeof(visited));
		for (int i=0; i<1001; i++) adj[i].clear();
		int u;
		cin >> n >> m >> u;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
		}
		dfs(u);
		cout << endl;
	}
	return 0;
}
