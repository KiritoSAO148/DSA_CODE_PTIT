#include <bits/stdc++.h>
using namespace std;

int n,m,s,T;
vector <int> adj[1001];
bool visited[1001];
int parent[1001];

void bfs(int u){
	queue <int> q;
	q.push(u);
	visited[u]=true;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x]=true;
				parent[x]=v;
			}
		}
	}
}

void Path(int s, int t){
	memset(visited,false,sizeof(visited));
	memset(parent,0,sizeof(parent));
	bfs(s);
	if (!visited[t]){
		cout << "-1\n";
	}else{
		vector <int> path;
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
