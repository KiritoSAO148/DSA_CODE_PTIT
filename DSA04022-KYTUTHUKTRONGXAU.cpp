#include <bits/stdc++.h>
using namespace std;

char solve (int n, long long k){
	long long x = pow(2,n-1);
	if (k==x) return 'A'+(n-1);
	if (k<x) return solve(n-1,k);
	return solve(n-1,k-x);
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		long long k; cin >> k;
		cout << solve(n,k) << endl;
	}
	return 0;
}
