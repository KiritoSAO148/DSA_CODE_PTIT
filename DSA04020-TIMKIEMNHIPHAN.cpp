#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		bool ok=false;
		int l=0, r=n-1;
		while (l<=r){
			int m=(l+r)/2;
			if (a[m]==k){
				cout << m+1 << endl;
				ok=true;
				break;
			}else if (a[m]>k) r=m-1;
			else l=m+1;
		}
		if (!ok) cout << "NO\n";
	}
	return 0;
}
