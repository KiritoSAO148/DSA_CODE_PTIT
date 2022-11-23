#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cin.ignore();
		string s; getline(cin,s);
		set<char>se;
		for (char x : s){
			if (x!=' ') se.insert(x);
		}
		for (char x : se) cout << x << " ";
		cout << endl;
	}
	return 0;
}
