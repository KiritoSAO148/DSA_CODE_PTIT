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
vii adj[1001];
int d[1001];

void inp(){
	for (int i=1; i<=n; i++) adj[i].clear();
	cin >> n >> m >> u;
	for (int i=0; i<m; i++){
		int x,y,w; cin >> x >> y >> w;
		adj[x].pb({y,w});
		adj[y].pb({x,w});
	}
}

void dijkstra(int s){
	for (int i=1; i<=n; i++) d[i]=1e9;
	priority_queue<pi, vii, greater<pi>>q;
	q.push({0,s});
	d[s]=0;
	while (!q.empty()){
		pi top=q.top(); q.pop();
		int u=top.se;
		int len=top.fi;
		if (len>d[u]) continue;
		for (pi it : adj[u]){
			int v=it.fi;
			int w=it.se;
			if (d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	for (int i=1; i<=n; i++) cout << d[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		dijkstra(u);
	}
	return 0;
}

