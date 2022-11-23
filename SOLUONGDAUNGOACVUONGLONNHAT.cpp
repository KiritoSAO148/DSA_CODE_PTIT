#include <bits/stdc++.h>
using namespace std;

int solve (string s){
	stack<char>st;
	int cnt=0;
	for (char x : s){
		if (st.empty() || x=='(' || x=='[') st.push(x);
		else{
			if (x==']'){
				if (st.top()=='(') continue;
				if (!st.empty()){
					++cnt; st.pop();
				}
			}
			else if (x==')'){
				if (st.top()=='(') st.pop();
			}
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s; getline(cin,s);
	cout << solve(s) << "\n";
	return 0;
}
