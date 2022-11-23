#include <bits/stdc++.h>
using namespace std;

string convert(int k, int n){
	string tmp="";
	while (n){
		tmp=to_string(n%k)+tmp;
		n/=k;
	}
	return tmp;
}

int solve(int k, string s){
	int tmp=0, n=s.size();
	for (int i=0; i<n; i++){
		tmp=tmp*k+(s[i]-'0');
	}
	return tmp;
}

int main(){
	int t; cin >> t;
	while (t--){
		int k; cin >> k;
		string a,b; cin >> a >> b;
		int res=solve(k,a)+solve(k,b);
		cout << convert(k,res) << endl;
	}
	return 0;
}
