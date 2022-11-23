#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	int a[n];
	for (int &x : a) cin >> x;
	sort(a,a+n);
	int cnt=1;
	for (int i=1; i<n; i++){
		if (abs(a[i]-a[i-1])>k) ++cnt;
	}
	cout << cnt << endl;
	return 0;
}
