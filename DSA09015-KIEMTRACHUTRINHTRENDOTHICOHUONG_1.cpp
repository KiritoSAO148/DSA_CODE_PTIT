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
vi adj[1001];
int color[1001];
int ing[1001];

void inp(){
	ms(color,0);
	ms(ing,0);
	for (int i=1; i<=n; i++) adj[i].clear();
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		ing[y]++;
	}
}

bool dfs (int u){
	color[u]=1;
	for (int v : adj[u]){
		if (color[v]==0){
			if (dfs(v)) return true;
		}
		else if (color[v]==1) return true;
	}
	color[u]=2;
	return false;
}

void kahn(){
	queue<int>q;
	for (int i=1; i<=n; i++){
		if (ing[i]==0) q.push(i);
	}
	int cnt=0;
	while (!q.empty()){
		int v=q.front(); q.pop();
		++cnt;
		for (int x : adj[v]){
			--ing[x];
			if(ing[x]==0) q.push(x);
		}
	}
	if (cnt==n) cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		bool ok=false;
		for (int i=1; i<=n; i++){
			if (color[i]==0 && dfs(i)){
				ok=true; break;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

