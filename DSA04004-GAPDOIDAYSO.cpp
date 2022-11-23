#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solve (int n, ll k){
	ll x=pow(2,n-1);
	if (k==x) return n;
	if (k<x) return solve(n-1,k);
	return solve(n-1,k-x);
}

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
		ll k; cin >> k;
		cout << solve(n,k) << endl;
	}
	return 0;
}
