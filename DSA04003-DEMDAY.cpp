#include <bits/stdc++.h>
using namespace std;

const int MOD = 123456789;
using ll = long long;

ll powMod (int n, ll k){
	if (k==0) return 1;
	ll x = powMod(n,k/2);
	if (k%2==0) return x*x%MOD;
	return n*(x*x%MOD)%MOD;
}

int main(){
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		cout << powMod(2,n-1) << endl;
	}
	return 0;
}
