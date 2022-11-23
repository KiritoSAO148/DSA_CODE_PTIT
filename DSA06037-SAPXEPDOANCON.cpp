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
		int n; cin >> n;
		int a[n+5], l[n+5], r[n+5];
		for (int i=0; i<n; i++) cin >> a[i];
		vi v;
		l[0]=a[0];
		r[n-1]=a[n-1];
		for (int i=1; i<n; i++){
			if (a[i]>l[i-1]) l[i]=a[i];
			else l[i]=l[i-1];
		}
		for (int i=n-2; i>=0; i--){
			if (a[i]<r[i+1]) r[i]=a[i];
			else r[i]=r[i+1];
		}
		for (int i=0; i<n-1; i++){
			if (l[i]<=r[i+1]) v.pb(i+1);
		}
		cout << sz(v) << "\n";
		for (int x : v) cout << x << " ";
		cout << "\n";
	}
	return 0;
}