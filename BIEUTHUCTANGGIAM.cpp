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
	for (int i=1; i<=t; i++){
		string s; cin >> s;
		stack<int>st;
		cout << "Test " << i << ": ";
		for (int j=0; j<=sz(s); j++){
			if (s[j]=='I' || j==sz(s)){
				cout << j+1;
				while (!st.empty()){
					cout << st.top();
					st.pop();
				}
			}else if (s[j]=='D') st.push(j+1);
		}
		cout << "\n";
	}
	return 0;
}