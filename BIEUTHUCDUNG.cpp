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

int solve (string s){
	stack<char>st;
	int ans=0, cnt=0;
	for (int i=0; i<sz(s); i++){
		if (s[i]=='('){
			st.push(s[i]);
			++cnt;
		}
		else{
			if (s[i]==')'){
				if (sz(st)==0) return -1;
			}else{
				st.pop();
				ans=max(ans,cnt);
				--cnt;
			}
		}
	}
	return ans;
}

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
		cout << solve(s) << "\n";
	}
	return 0;
}