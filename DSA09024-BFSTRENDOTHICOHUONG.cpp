#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void bfs(int u){
	queue <int> q;
	q.push(u);
	visited[u]=true;
	while (!q.empty()){
		int v = q.front(); q.pop();
		cout << v << " ";
		for (int x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x]=true;
			}
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
		bfs(u);
		cout << endl;
	}
	return 0;
}
