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

int n;
vi adj[1001];
bool visited[1001];
int par[1001];
vi leaf;

void inp(){
	cin >> n;
	for (int i=1; i<=n; i++) adj[i].clear();
	ms(visited,false);
	ms(par,0);
	leaf.clear();
	for (int i=0; i<n-1; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for (int i=2; i<=n; i++){
		if (sz(adj[i])==1) leaf.pb(i);
	}
}

void dfs (int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]){
			par[v]=u;
			dfs(v);
		}
	}
}

void findPath (int u, int v){
	vi path;
	while (v!=u){
		path.pb(v);
		v=par[v];
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
		dfs(1);
		for (int x : leaf){
			findPath(1,x);
		}
	}
	return 0;
}