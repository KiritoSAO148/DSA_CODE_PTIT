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
int d[101][101];

void inp(){
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (i==j) d[i][j]=0;
			else d[i][j]=1e9;
		}
	}
	for (int i=0; i<m; i++){
		int x,y,w; cin >> x >> y >> w;
		d[x][y]=d[y][x]=w;
	}
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int q; cin >> q;
	while (q--){
		int x,y; cin >> x >> y;
		cout << d[x][y] << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	inp();
	return 0;
}

