#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
using ll = long long;

ll powMod (int n, ll k){
	if (k == 0) return 1;
	ll x = powMod(n,k/2);
	if (k % 2 == 0) return x * x % MOD;
	return n * (x * x % MOD) % MOD;
}

int main(){
	while (1){
		int n; cin >> n;
		ll k; cin >> k;
		if (n==0 && k==0) break;
		cout << powMod(n,k) << endl;
	}
	return 0;
}
