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
vi adj[1000001];
bool visited[1000001];
int d[1000001];

void inp(){
	for (int i=1; i<=n; i++){
		visited[i]=false;
		d[i]=0;
	}
	cin >> n;
	for (int i=1; i<=n; i++) adj[i].clear();
	for (int i=0; i<n-1; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void bfs (int u){
	queue<int>q;
	q.push(u);
	visited[u]=true;
	d[u]=0;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				visited[x]=true;
				q.push(x);
				d[x]=d[v]+1;
			}
		}
	}
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
		bfs(1);
		cout << *max_element(d+1,d+n+1) << "\n";
	}
	return 0;
}