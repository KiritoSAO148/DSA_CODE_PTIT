#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	cin.ignore();
	while (t--){
		string s; getline(cin,s);
		stack<char>st;
		for (int i=0; i<s.size(); i++){
			if (st.empty() || s[i]=='(' || s[i]=='[') st.push(s[i]);
			else{
				if (s[i]==')'){
					if (st.top()=='(') st.pop();
					else{
						cout << "NO\n"; return 0;
					}
				}
				else if (s[i]==']'){
					if (st.top()=='[') st.pop();
					else{
						cout << "NO\n"; return 0;
					}
				}
			}
		}
		if (!st.empty()){
			cout << "NO\n"; return 0;
		}
		cout << "YES\n";
	}
	return 0;
}