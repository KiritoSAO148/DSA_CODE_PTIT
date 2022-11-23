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

int m,n,a[1000][1000],cnt;

void Try(int i, int j){
	if (i==m && j==n){
		++cnt;
		return;
	}
	if (i+1>0 && i+1<=m){
		Try(i+1,j);
	}
	if (i>0 && j+1<=n){
		Try(i,j+1);
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> m >> n;
		for (int i=1; i<=m; i++){
			for (int j=1; j<=n; j++){
				cin >> a[i][j];
			}
		}
		cnt=0;
		Try(1,1);
		cout << cnt << endl;
	}
	return 0;
}
