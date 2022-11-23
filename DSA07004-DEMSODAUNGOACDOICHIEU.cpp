#include <bits/stdc++.h>
using namespace std;

int solve(string s){
	stack<char>st;
	int cnt=0, n=s.size();
	for (int i=0; i<n; i++){
		if (s[i] == '(') st.push(s[i]);
		else{
			if (!st.empty()) st.pop();
			else{
				st.push('(');
				++cnt;
			}
		}
	}
	return cnt + st.size()/2;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}
