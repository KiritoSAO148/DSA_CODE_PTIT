#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

ll powMod (ll n, int k){
	if (k==0) return 1;
	ll x = powMod(n,k/2);
	if (k%2==0) return x*x%MOD;
	return n*(x*x%MOD)%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		int k; cin >> k;
		ll ans=0;
		for (int i=1; i<=n; i++){
			ans+=powMod(i,k);
			ans%=MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
