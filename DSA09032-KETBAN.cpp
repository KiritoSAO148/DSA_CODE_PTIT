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
int par[1000001],sz[1000001];

int find (int u){
	if (u==par[u]) return u;
	return par[u]=find(par[u]);
}

bool Union(int a, int b){
	a=find(a);
	b=find(b);
	if (a==b) return false;
	if (sz[a]>sz[b]){
		par[b]=a;
		sz[a]+=sz[b];
	}
	else{
		par[a]=b;
		sz[b]+=sz[a];
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			par[i]=i;
			sz[i]=1;
		}
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			Union(x,y);
		}
		cout << *max_element(sz+1,sz+n+1) << "\n";
	}
	return 0;
}