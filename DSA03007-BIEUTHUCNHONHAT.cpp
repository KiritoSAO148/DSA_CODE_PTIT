#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll a[n],b[n];
		for (ll &x : a) cin >> x;
		for (ll &x : b) cin >> x;
		ll ans=0;
		sort(a,a+n);
		sort(b,b+n,greater<ll>());
		int i=0;
		while (i<n){
			ans+=a[i]*b[i];
			++i;
		}
		cout << ans << endl;
	}
	return 0;
}
