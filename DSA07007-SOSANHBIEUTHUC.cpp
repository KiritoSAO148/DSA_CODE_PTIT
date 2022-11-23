#include <bits/stdc++.h>
using namespace std;

string solve(string s){
	stack<char>st;
	int n=s.size();
	for (int i=0; i<n; i++){
		if (s[i]=='('){
			char c=s[i-1];
			if (c=='-' || c=='+') st.push(c);
			if (c=='(' && !st.empty()) st.push(st.top());
		}
		if (!st.empty() && st.top()=='-'){
			if (s[i]=='-') s[i]='+';
			else if (s[i]=='+') s[i]='-';
		}
		if (s[i]==')' && !st.empty()) st.pop();
	}
	string ans="";
	for (int i=0; i<n; i++){
		if (s[i]=='(' || s[i]==')') continue;
		ans+=s[i];
	}
	return ans;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s1, s2; cin >> s1 >> s2;
		if (solve(s1)==solve(s2)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
