#include <bits/stdc++.h>
using namespace std;

int solve (string s){
	stack<char>st;
	int res=0;
	for (int i=0; i<s.size(); i++){
		if (st.empty() || s[i]=='(') st.push(s[i]);
		else if (st.top()=='('){
			res+=2;
			st.pop();
		}
	}
	int check=0;
	while (!st.empty()){
		if (st.top()=='('){
			if (check){
				res+=2;
				check=0;
			}
			st.pop();
		}else{
			st.pop();
			check=1;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << solve(s) << "\n";
	}
	return 0;
}

