#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		long long ans=0;
		stack<int>st;
		int i=0;
		while (i<n){
			if (st.empty() || a[i]>=a[st.top()]){
				st.push(i);
				++i;
			}else{
				int top=st.top(); st.pop();
				if (st.empty()) ans=max(ans,1ll*i*a[top]);
				else ans=max(ans,1ll*a[top]*(i-st.top()-1));
			}
		}
		while (!st.empty()){
			int top=st.top(); st.pop();
			if (st.empty()) ans=max(ans,1ll*i*a[top]);
			else ans=max(ans,1ll*a[top]*(i-st.top()-1));
		}
		cout << ans << endl;
	}
	return 0;
}
