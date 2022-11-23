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

struct canh{
	int x,y,w;
};

int n,m;
vector<canh>dscanh;
int par[1001], size[1001];

int find (int u){
	if (u==par[u]) return u;
	return par[u]=find(par[u]);
}

bool Union(int a, int b){
	a=find(a);
	b=find(b);
	if (a==b) return false;
	if (size[a]>size[b]){
		par[b]=a;
		size[a]+=size[b];
	}
	else{
		par[a]=b;
		size[b]+=size[a];
	}
	return true;
}

void inp(){
	dscanh.clear();
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x,y,w; cin >> x >> y >> w;
		dscanh.pb({x,y,w});
	}
	for (int i=1; i<=n; i++){
		par[i]=i;
		size[i]=1;
	}
}

bool cmp(canh a, canh b){
	return a.w < b.w;
}

void kruskal(){
	sort(all(dscanh),cmp);
	int ans=0;
	vector<canh>mst;
	for (int i=0; i<m; i++){
		if (sz(mst)==n-1) break;
		if (Union(dscanh[i].x,dscanh[i].y)){
			mst.pb(dscanh[i]);
			ans+=dscanh[i].w;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		kruskal();
	}
	return 0;
}

