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
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,m;
vi adj[1001];
bool visited[1001];
int indeg[1001];

vi kahn;

void inp(){
	cin >> n >> m;
	kahn.clear();
	for (int i=1; i<=n; i++) adj[i].clear();
	ms(visited,false);
	ms(indeg,0);
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
		indeg[y]++;
	}
}

void topo(){
	queue<int>q;
	for (int i=1; i<=n; i++){
		if (!indeg[i]) q.push(i);
	}
	while (!q.empty()){
		int v=q.front(); q.pop();
		kahn.pb(v);
		for (int x : adj[v]){
			indeg[x]--;
			if (indeg[x]==0) q.push(x);
		}
	}
	if (sz(kahn)<n) cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		topo();
	}
	return 0;
}

