#include <bits/stdc++.h>
using namespace std;

bool solve (int a[], int n, int sum){
	sort(a,a+n);
	for (int i=0; i<n-2; i++){
		int l=i+1, r=n-1;
		while (l<r){
			if (a[i]+a[l]+a[r]==sum) return true;
			else if (a[i]+a[l]+a[r]<sum) ++l;
			else --r;
		}
	}
	return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		int a[n];
		for (int &x : a) cin >> x;
		if (solve(a,n,k)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
