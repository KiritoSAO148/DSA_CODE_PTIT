#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
using ll = long long;

ll rev (ll n){
	ll tmp=0;
	while (n){
		tmp=tmp*10+n%10;
		n/=10;
	}
	return tmp;
}

ll powMod (ll n, ll k){
	if (k==0) return 1;
	ll x=powMod(n,k/2);
	if (k%2==0) return x*x%MOD;
	return n*(x*x%MOD)%MOD;
}

int main(){
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		cout << powMod(n,rev(n)) << endl;
	}
	return 0;
}
