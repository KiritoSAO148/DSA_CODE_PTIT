#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		int e1=-1, e2=-1, min=INT_MAX;
		for (int i=0; i<n-1; i++){
			for (int j=i+1; j<n; j++){
				if (abs(a[i]+a[j])<min){
					min=abs(a[i]+a[j]);
					e1=a[i];
					e2=a[j];
				}
			}
		}
		cout << e1+e2 << endl;
	}
	return 0;
}
