#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,a[100][100],ok;

int dx[2]={1,0};
int dy[2]={0,1};
string s="DR";

void Try(int i, int j, string res){
	if (i==n && j==n){
		cout << res << " ";
		ok=1;
	}
	for (int k=0; k<2; k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if (i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]){
			a[i1][j1]=0;
			Try(i1,j1,res+s[k]);
			a[i1][j1]=1;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				cin >> a[i][j];
			}
		}
		ok=0;
		if (a[1][1] && a[n][n]){
			a[1][1]=0;
			Try(1,1,"");
		}
		if (ok) cout << endl;
		else cout << -1 << endl;
	}
	return 0;
}
