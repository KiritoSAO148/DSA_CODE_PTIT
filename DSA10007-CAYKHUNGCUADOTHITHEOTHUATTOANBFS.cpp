#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
#define fi first
#define se second
#define pb push_back
int n,m,u;
vector<int>adj[1001];
vector<pi>ans;
bool visited[1001];

void bfs(int u){
	queue<int>q;
	q.push(u);
	visited[u]=true;
	while (!q.empty()){
		int top = q.front(); q.pop();
		for (int v : adj[top]){
			if (!visited[v]){
				ans.pb({top,v});
				visited[v]=true;
				q.push(v);
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		memset(visited,false,sizeof(visited));
		for (int i=1; i<=n; i++) adj[i].clear();
		ans.clear();
		cin >> n >> m >> u;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		bfs(u);
		if (ans.size()!=n-1) cout << -1 << endl;
		else{
			for (auto it : ans) cout << it.fi << ' ' << it.se << "\n";
		}
	}
	return 0;
}
