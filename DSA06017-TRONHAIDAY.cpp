#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n,m; cin >> n >> m;
		int a[n],b[m];
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		sort(a,a+n);
		sort(b,b+m);
		int l=0, r=0;
		while(l<n && r<m){
			if (a[l]<=b[r]){
				cout << a[l] << " ";
				++l;
			}else{
				cout << b[r] << " ";
				++r;
		}
	}
		while (l<n){
			cout << a[l] << " ";
			++l;
		}
		while (r<m){
			cout << b[r] << " ";
			++r;
		}
		cout << endl;
	}
	return 0;
}
