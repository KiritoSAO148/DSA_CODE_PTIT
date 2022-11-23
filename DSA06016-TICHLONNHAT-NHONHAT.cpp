#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while (t--){
		int n,m; cin >> n >> m;
		int a[n], b[m];
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		int res=*max_element(a,a+n);
		int ans=*min_element(b,b+n);
		cout << 1ll*res*ans << endl;
	}
	return 0;
}
