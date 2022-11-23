#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		vector <int> v(a,a+n);
		sort(v.begin(),v.end());
		bool ok=true;
		for (int i=0; i<n; i++){
			if (a[i]!=v[i] && a[i]!=v[n-i-1]){
				cout << "No\n";
				ok=false;
				break;
			}
		}
		if (ok) cout << "Yes\n";
	}
	return 0;
}
