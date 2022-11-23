#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		int res=1e9;
		sort(a,a+n);
		for (int i=0; i<n-1; i++) res=min(res,a[i+1]-a[i]);
		cout << res << endl;
	}
}
