#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		string s; getline(cin,s);
		string ans="";
		for (int i=0; i<s.size(); i++){
			if (s[i]=='(' || s[i]==')') ans+=s[i];
		}
		stack<int>st;
		int cnt=0;
		memset(a,0,sizeof(a));
		for (int i=0; i<ans.size(); i++){
			if (ans[i]=='('){
				++cnt;
				a[i]=cnt;
				st.push(i);
			}else{
				a[i]=a[st.top()];
				st.pop();
			}
		}
		for (int i=0; i<ans.size(); i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
