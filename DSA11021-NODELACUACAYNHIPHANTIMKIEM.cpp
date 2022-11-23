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

void solve (int pre[], int n){
	stack<int>st;
	int i=0, j=1;
	while (j < n){
		bool found = false;
		if (pre[i] > pre[j]) st.push(pre[i]);
		else{
			while (!st.empty()){
				if (pre[j] > st.top()){
					st.pop();
					found = true;
				}else break;
			}
		}
		if (found) cout << pre[i] << " ";
		++i; ++j;
	}
	cout << pre[n-1] << "\n";
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
	while (t--){
		int n; cin >> n;
		int pre[n];
		for (int i=0; i<n; i++) cin >> pre[i];
		solve(pre, n);
	}
	return 0;
}