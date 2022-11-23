#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int firstPos (int a[], int l, int r, int x){
	int res=-1;
	while (l<=r){
		int m=(l+r)/2;
		if (a[m]<x){
			res=m;
			l=m+1;
		}
		else r=m-1;
	}
	return res;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a,a+n);
		ll cnt=0;
		for (int i=0; i<n-1; i++){
			int res=firstPos(a,i+1,n-1,k+a[i]);
			//auto it=lower_bound(a+i+1,a+n,k+a[i]);
			if (res!=-1) cnt+=res-i;
			//cnt+=it-(a+i)-1;
		}
		cout << cnt << endl;
	}
	return 0;
}
