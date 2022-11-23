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

int n,m;
vi adj[100001], radj[100001];
bool visited[100001];
stack<int>topo;

void inp(){
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		radj[y].pb(x);
	}
}

void dfs1 (int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]) dfs1(v);
	}
	topo.push(u);
}

void dfs2 (int u){
	visited[u]=true;
	for (int v : radj[u]){
		if (!visited[v]) dfs2(v);
	}
}

void kosaraju(){
	for (int i=1; i<=n; i++){
		if (!visited[i]) dfs1(i);
	}
	ms(visited,false);
	int cnt=0;
	while (!topo.empty()){
		int v=topo.top(); topo.pop();
		if (!visited[v]){
			++cnt;
			dfs2(v);
		}
	}
	cout << cnt;
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	inp();
	kosaraju();
	return 0;
}