#include <bits/stdc++.h>
using namespace std;

string solve(string s){
	stack<string>st;
	for (int i=0; i<s.size(); i++){
		if (isalpha(s[i])) st.push(string(1,s[i]));
		else{
			string o1 = st.top(); st.pop();
			string o2 = st.top(); st.pop();
			string ex = "(" + o2 + s[i] + o1 + ")";
			st.push(ex);
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
