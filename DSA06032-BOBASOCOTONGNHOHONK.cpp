#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while (t--){
		ll n,k; cin >> n >> k;
		ll a[n];
		for (ll &x : a) cin >> x;
		sort(a,a+n);
		ll ans=0;
		for (int i=0; i<n-2; i++){
			for (int j=i+1; j<n-1; j++){
				ans+=lower_bound(a+j+1, a+n, k-a[i]-a[j])-a-j-1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
