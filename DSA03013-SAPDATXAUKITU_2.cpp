#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int d; cin >> d;
		string s; cin >> s;
		int a['z'+1]={0};
		int n=s.size();
		for (int i=0; i<n; i++) a[s[i]]++;
		int m=*max_element(a,a+'z');
		if ((m-1)*d<n) cout << 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}
