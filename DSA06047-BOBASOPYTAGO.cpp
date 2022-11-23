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

bool solve (ll a[], int n){
	for (int i=0; i<n; i++)
		a[i]=a[i]*a[i];
	sort(a,a+n);
	for (int i=n-1; i>=2; --i){
		int l=0, r=i-1;
		while (l<r){
			if (a[l]+a[r]==a[i]) return true;
			if (a[l]+a[r]<a[i]) ++l;
			else --r;
		}
	}
	return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll a[n];
		for (ll &x : a) cin >> x;
		if (solve(a,n)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

