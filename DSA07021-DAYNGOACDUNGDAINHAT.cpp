#include <bits/stdc++.h>
using namespace std;

int solve(string s){
	int n=s.size(), ans=0;
	stack<int>st;
	st.push(-1);
	for (int i=0; i<n; i++){
		if (s[i] == '(') st.push(i);
		else{
			st.pop();
			if (!st.empty()){
				ans=max(ans,i-st.top());
			}
			else st.push(i);
		}
	}
	return ans;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << solve(s) << "\n";
	}
	return 0;
}
