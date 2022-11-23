#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll f[100];

void init(){
	f[0]=0; f[1]=1;
	for (int i=2; i<=92; i++) f[i]=f[i-1]+f[i-2];
}

char solve (int n, ll k){
	if (n==1) return 'A';
	if (n==2) return 'B';
	if (k<=f[n-2]) return solve (n-2,k);
	return solve (n-1,k-f[n-2]);
}

int main(){
	int t; cin >> t;
	init();
	while (t--){
		int n; cin >> n;
		ll k; cin >> k;
		cout << solve(n,k) << endl;
	}
	return 0;
}
