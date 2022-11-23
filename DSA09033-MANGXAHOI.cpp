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

int n,m,cnt;
vi adj[1000001];
bool visited[1000001];
vi tplt;

void inp(){
	cin >> n >> m;
	for (int i=1; i<=n; i++) adj[i].clear();
	ms(visited,false);
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void dfs (int u){
	++cnt;
	visited[u]=true;
	tplt.pb(u);
	for (int v : adj[u]){
		if (!visited[v]) dfs(v);
	}
}

bool check(){
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			cnt=0;
			tplt.clear();
			dfs(i);
			for (int x : tplt){
				if (sz(adj[x])<cnt-1) return false;
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		if (check()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}