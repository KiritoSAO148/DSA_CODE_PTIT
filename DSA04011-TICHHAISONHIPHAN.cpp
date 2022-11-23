#include <bits/stdc++.h>
using namespace std;

long long solve(string s){
	long long res=0, base=1;
	for (int i=s.size()-1; i>=0; i--){
		res+=(s[i]-'0')*base;
		base*=2;
	}
	return res;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s1,s2; cin >> s1 >> s2;
		cout << solve(s1)*solve(s2) << endl;
	}
	return 0;
}
