#include <bits/stdc++.h>
using namespace std;

int find(int a[], int n, int x){
	int res=-1;
	int l=0, r=n-1;
	while (l<=r){
		int m=(l+r)/2;
		if (a[m]<=x){
			res=m+1;
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
		cout << find(a,n,k) << endl;
	}
	return 0;
}
