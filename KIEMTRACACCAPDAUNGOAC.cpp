#include <bits/stdc++.h>
using namespace std;

string check (string s){
	stack<char>st;
	for (char x : s){
		if (st.empty() || x=='(' || x=='[' || x=='{') st.push(x);
		else{
			if (x==')'){
				if (st.top()=='(') st.pop();
				else return "false\n";
			}
			if (x==']'){
				if (st.top()=='[') st.pop();
				else return "false\n";
			}
			if (x=='}'){
				if (st.top()=='{') st.pop();
				else return "false\n";
			}
		}
	}
	if (!st.empty()) return "false\n";
	return "true\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << check(s);
	}
	return 0;
}

