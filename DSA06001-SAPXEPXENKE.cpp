#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		sort (a,a+n,greater<int>());
		int l=0,r=n-1;
		while (l<=r){
			if (l==r){
				cout << a[l];
				break;
			}else{
				cout << a[l] << " " << a[r] << " ";
				++l;--r;
			}
		}
		cout << endl;
	}
	return 0;
}
