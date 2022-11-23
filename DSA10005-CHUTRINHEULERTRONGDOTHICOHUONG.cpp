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

vi adj1[1001],adj2[1001];

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
		int n,m; cin >> n >> m;
		for (int i=1; i<=n; i++){
			adj1[i].clear();
			adj2[i].clear();
		}
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj1[x].pb(y);
			adj2[y].pb(x);
		}
		int cnt=0;
		for (int i=1; i<=n; i++){
			if (sz(adj1[i])==sz(adj2[i])) ++cnt;
		}
		if (cnt==n) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}