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

int main(){
	int t; cin >> t;
	while (t--){
		int n,m; cin >> n >> m;
		int a[n],b[m];
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		vector <int> hop;
		vector <int> giao;
		int i=0, j=0;
		while (i<n && j<m){
			if (a[i]<b[j]){
				hop.pb(a[i]);
				++i;
			}
			else if (a[i]>b[j]){
				hop.pb(b[j]);
				++j;
			}else{
				hop.pb(a[i]);
				giao.pb(a[i]);
				++i;++j;
			}
		}
		while (i<n){
			hop.pb(a[i++]);
		}
		while (j<m){
			hop.pb(b[j++]);
		}
		for (auto x : hop) cout << x << " ";
		cout << endl;
		for (auto x : giao) cout << x << " ";
		cout << endl;
	}
	return 0;
}
