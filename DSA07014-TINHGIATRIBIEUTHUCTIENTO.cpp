#include <bits/stdc++.h>
using namespace std;

int op (int a, int b, char c){
	if (c=='+') return a+b;
	if (c=='-') return a-b;
	if (c=='*') return a*b;
	if (c=='/') return a/b;
	if (c=='%') return a%b;
}

int solve(string s){
	stack<int>st;
	int ans=0, n=s.size();
	for (int i=n-1; i>=0; i--){
		if (isdigit(s[i])) st.push(s[i]-'0');
		else{
			int o1=st.top(); st.pop();
			int o2=st.top(); st.pop();
			int tmp=op(o1,o2,s[i]);
			st.push(tmp);
		}
	}
	return st.top();
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}
