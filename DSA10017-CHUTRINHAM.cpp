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

void inp(){
	cin >> n >> m;
	dscanh.clear();
	for (int i=0; i<m; i++){
		int x,y,w; cin >> x >> y >> w;
		dscanh.pb({x,y,w});
	}
}

bool Bellman_Ford (int s, int d[]){
	for (int i=0; i<n; i++) d[i]=1e9;
	d[s]=0;
	for (int i=1; i<=n-1; i++){
		for (int j=0; j<m; j++){
			canh tmp=dscanh[j];
			int x=tmp.x, y=tmp.y, w=tmp.w;
			if (d[x]<1e9){
				d[y]=min(d[y],d[x]+w);
			}
		}
	}
	for (int i=0; i<m; i++){
		canh tmp=dscanh[i];
		int x=tmp.x, y=tmp.y, w=tmp.w;
		if (d[x]<1e9 && d[x]+w<d[y]) return true;
	}
	return false;
}

bool check(){
	bool visited[n];
	ms(visited,false);
	int d[n];
	for (int i=0; i<n; i++){
		if (!visited[i]){
			if (Bellman_Ford(i,d)) return true;
			for (int i=0; i<n; i++){
				if (d[i]<1e9) visited[i]=true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		if (check()) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

