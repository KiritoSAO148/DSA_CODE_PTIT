#include <bits/stdc++.h>
using namespace std;

int tinh1(int a, int b, char c){
	if (c=='+') return a+b;
	if (c=='-') return a-b;
	if (c=='*') return a*b;
	if (c=='/') return a/b;
	if (c=='%') return a%b;
}

int tinh(string s){
	stack<int>st;
	int ans=0, n=s.size();
	for (int i=0; i<n; i++){
		if (isdigit(s[i])) st.push(s[i]-'0');
		else{
			int o1 = st.top(); st.pop();
			int o2 = st.top(); st.pop();
			int tmp = tinh1(o2,o1,s[i]);
			st.push(tmp);
		}
	}
	return st.top();
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << tinh(s) << endl;
	}
	return 0;
}
