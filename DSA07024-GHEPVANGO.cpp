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
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		stack<int>st;
		int ans=0;
		int i=0;
		while (i<n){
			if (st.empty() || a[i]>=a[st.top()]){
				st.push(i);
				++i;
			}else{
				int top=st.top(); st.pop();
				if (st.empty()){
					if (a[top]<=i) ans=max(ans,a[top]);
				}
				else if (a[top]<=(i-st.top()-1)) ans=max(ans,a[top]);
			}
		}
		while (!st.empty()){
			int top=st.top(); st.pop();
			if (st.empty()){
				if (a[top]<=i) ans=max(ans,a[top]);
			}
			else if (a[top]<=(i-st.top()-1)) ans=max(ans,a[top]);
		}
		cout << ans << "\n";
	}
	return 0;
}