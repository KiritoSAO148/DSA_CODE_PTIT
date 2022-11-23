#include <bits/stdc++.h>
using namespace std;

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
		int a[n],b[n-1];
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n-1; i++) cin >> b[i];
		int pos=0;
		for (int i=0; i<n-1; i++){
			if (a[i]!=b[i]){
				pos=i+1;
				break;
			}
		}
		if (pos==0) cout << n;
		else cout << pos;
		cout << endl;
	}
	return 0;
}
