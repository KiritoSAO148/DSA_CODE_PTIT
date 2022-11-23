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
stack<int>st;

void inp(){
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		adj[i].clear();
		radj[i].clear();
	}
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
	st.push(u);
}

void dfs2 (int u){
	visited[u]=true;
	for (int v : radj[u]){
		if (!visited[v]) dfs2(v);
	}
}

void kosaraju(){
	ms(visited,false);
	for (int i=1; i<=n; i++){
		if (!visited[i]) dfs1(i);
	}
	ms(visited,false);
	int cnt=0;
	while (!st.empty()){
		int u=st.top(); st.pop();
		if (!visited[u]){
			++cnt;
			dfs2(u);
		}
	}
	if (cnt==1) cout << "YES\n";
	else cout << "NO " << cnt << "\n";
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
		kosaraju();
	}
	return 0;
}