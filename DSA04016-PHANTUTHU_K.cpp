#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n,m,k; cin >> n >> m >> k;
		int a[n],b[m];
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		sort(a,a+n);
		sort(b,b+m);
		int i=0,j=0;
		vector<int>v;
		for (int x : a) v.push_back(x);
		for (int x : b) v.push_back(x);
		sort(v.begin(),v.end());
		cout << v[k-1] << endl;
	}
	return 0;
}
