#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n){
	unordered_map<int,int> mp;
	for (int i=0; i<n; i++) mp[a[i]]++;
	int cnt=0;
	for (auto it : mp){
		if (it.second>n/2){
			cnt=1;
			cout << it.first << endl;
			break;
		}
	}
	if (cnt==0) cout << "NO\n";
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		solve(a,n);
	}
	return 0;
}
