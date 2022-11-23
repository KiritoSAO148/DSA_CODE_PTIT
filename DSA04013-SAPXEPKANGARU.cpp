#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		sort(a,a+n,greater<int>());
		int cnt=0;
		int l=0, r=n/2;
		while (l<n/2 && r<n){
			if (a[l]>=2*a[r]){
				++cnt;++l;++r;
			}else ++r;
		}
		cout << n-cnt << endl;
	}
	return 0;
}
