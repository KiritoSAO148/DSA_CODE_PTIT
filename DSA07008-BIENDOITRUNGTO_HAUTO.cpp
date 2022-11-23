#include <bits/stdc++.h>
using namespace std;

int uutien (char c){
	if (c=='^') return 3;
	if (c=='*' || c=='/') return 2;
	if (c=='+' || c=='-') return 1;
	return 0;
}

void solve(string s){
	string res="";
	stack<char>st; //luu toan tu va dau dong mo ngoac
	for (int i=0; i<s.size(); i++){
		if (isalpha(s[i])) res+=s[i];
		else if (s[i]=='(') st.push(s[i]);
		else if (s[i]==')'){
			while (!st.empty() && st.top()!='('){
				res+=st.top();
				st.pop();
			}
			st.pop(); //xoa bo dau mo ngoac tuong ung
		}else{ 
			//khi gap toan tu
			while (!st.empty() && uutien(s[i])<=uutien(st.top())){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()){
		res+=st.top();
		st.pop();
	}
	cout << res << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		solve(s);
	}
	return 0;
}
