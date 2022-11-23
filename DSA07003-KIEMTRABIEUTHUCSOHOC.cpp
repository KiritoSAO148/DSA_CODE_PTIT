#include <bits/stdc++.h>
using namespace std;

bool solve (string s){
	stack<char>st;
	for (char c : s){
		if (c==')'){
			int ok=1;
			while (st.top()!='('){
				if (st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/') ok=0;
				st.pop();
			}
			if (ok) return true;
		}
		else st.push(c);
	}
	return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		if (solve(s)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
