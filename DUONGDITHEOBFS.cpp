#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n,m,u;
vi adj[1001];
bool visited[1001];
int par[1001];

void inp(){
	cin >> n >> m >> u;
	for (int i=1; i<=n; i++) adj[i].clear();
	ms(visited,false);
	ms(par,0);
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void bfs (int u){
	queue<int>q;
	q.push(u);
	visited[u]=true;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				visited[x]=true;
				par[x]=v;
				q.push(x);
			}
		}
	}
}

void findPath (int u, int t){
	bfs(u);
	if (!visited[t]){
		cout << "No path\n"; return;
	}
	if (u==t) return;
	vi path;
	while (t!=u){
		path.pb(t);
		t=par[t];
	}
	path.pb(u);
	reverse(all(path));
	for (int x : path) cout << x << " ";
	cout << "\n";
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		for (int i=1; i<=n; i++){
			findPath(u,i);
		}
	}
	return 0;
}