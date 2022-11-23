#include <bits/stdc++.h>
using namespace std;

void solve(string s){
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
	for (int i=0; i<n; i++){
		if (s[i]=='(' || s[i]==')') continue;
		cout << s[i];
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		solve(s);
		cout << "\n";
	}
	return 0;
}
