#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int bs (int a[], int l, int r, int x){
	int res=-1;
	while (l<=r){
		int m=(l+r)/2;
		if (a[m]<x){
			res=m;
			l=m+1;
		}else r=m-1;
	}
	return res;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		int a[n];
		for (int &x : a) cin >> x;
		sort(a,a+n);
		ll cnt=0;
		for (int i=0; i<n-1; i++){
			int res=bs(a,i+1,n-1,k+a[i]);
			if (res!=-1) cnt+=res-i;
		}
		cout << cnt << endl;
	}
	return 0;
}
