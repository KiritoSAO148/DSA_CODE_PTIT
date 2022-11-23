#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		vector<int>res[n];
		for (int &x : a) cin >> x;
		for (int i=0; i<n-1; i++){
			bool ok=false;
			for (int j=0; j<n-i-1; j++){
				if (a[j]>a[j+1]){
					swap(a[j],a[j+1]);
					ok=true;
				}
			}
			if (ok){
				for (int j=0; j<n; j++){
					res[i].pb(a[j]);
				}
			}else break;
		}
		for (int i=n-2; i>=0; i--){
			if (res[i].size()){
				cout << "Buoc " << i+1 << ": ";
				for (int x : res[i]) cout << x << " ";
				cout << endl;
			}
		}
	}
	return 0;
}
