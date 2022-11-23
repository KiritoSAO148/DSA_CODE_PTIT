#include <bits/stdc++.h>
using namespace std;

int n,m,s,T;
vector <int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]){
			parent[v]=u;
			dfs(v);
		}
	}
}

void Path(int s, int t){
	memset(visited,false,sizeof(visited));
	memset(parent,0,sizeof(parent));
	dfs(s);
	if (!visited[t]){
		cout << "-1\n"; return;
	}else{
		vector<int>path;
		while (t!=s){
			path.push_back(t);
			t=parent[t];
		}
		path.push_back(s);
		reverse(path.begin(),path.end());
		for (int x : path){
			cout << x << " ";
		}
		cout << endl;
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i=0; i<1001; i++) adj[i].clear();
		cin >> n >> m >> s >> T;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		Path(s,T);
	}
	return 0;
}
