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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	int cnt=0;
	while (t--){
		++cnt;
		string s; cin >> s;
		int n=s.size();
		stack<int>st;
		cout << "Test " << cnt << ": ";
		for (int i=0; i<=n; i++){
			if (s[i]=='I' || i==n){
				cout << i+1;
				while (!st.empty()){
					cout << st.top(); st.pop();
				}
			}else if (s[i]=='D') st.push(i+1);
		}
		cout << "\n";
	}
	return 0;
}

