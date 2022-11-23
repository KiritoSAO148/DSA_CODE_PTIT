#include <bits/stdc++.h>
using namespace std;

void dp(int a[], int n){
	int s=0, e=0;
	for (int i=0; i<n; i++){
		e=max(a[i],e+a[i]);
		s=max(s,e);
	}
	cout << s << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		dp(a,n);
	}
	return 0;
}
