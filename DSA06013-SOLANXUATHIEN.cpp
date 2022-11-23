#include <bits/stdc++.h>
using namespace std;

int first_pos(int a[], int n, int x){
	int l=0, r=n-1;
	int res=-1;
	while (l<=r){
		int m=(l+r)/2;
		if (a[m]==x){
			res=m;
			r=m-1;
		}else if (a[m]>x){
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return res;
}

int last_pos(int a[], int n, int x){
	int l=0, r=n-1;
	int res=-1;
	while (l<=r){
		int m=(l+r)/2;
		if (a[m]==x){
			res=m;
			l=m+1;
		}else if (a[m]>x){
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return res;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n, x; cin >> n >> x;
		int a[n];
		for (int &x : a) cin >> x;
		int l=first_pos(a,n,x);
		int r=last_pos(a,n,x);
		if (l!=-1 && r!=-1){
			cout << r-l+1;
		}else{
			cout << -1;
		}
		cout << endl;
	}
	return 0;
}
