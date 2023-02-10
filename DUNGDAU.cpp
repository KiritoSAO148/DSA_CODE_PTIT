#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	string a[101];
	for (int i = 0; i < n; ++i) cin >> a[i];
	string s; cin >> s;
	vector <string> v;
	for (int i = 0; i < n; ++i){
		if (a[i] != s) v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	do{
		cout << s << ' ';
		for (string x : v) cout << x << ' ';
		cout << '\n';
	}while (next_permutation(v.begin(), v.end()));
	return 0;
}
