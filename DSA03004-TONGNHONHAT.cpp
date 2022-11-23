#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		sort(a,a+n);
		string s1="";
		string s2="";
		for (int i=0; i<n; i+=2) s1+=to_string(a[i]);
		for (int i=1; i<n; i+=2) s2+=to_string(a[i]);
		cout << stoll(s1)+stoll(s2) << endl;
	}
	return 0;
}
