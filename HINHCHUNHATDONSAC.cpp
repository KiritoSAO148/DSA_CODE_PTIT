#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int m,n; cin >> m >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	ll ans=0;
	stack<int>st;
	int i=0;
	while (i<n){
		if (st.empty() || a[i]>=a[st.top()]){
			st.push(i);
			++i;
		}else{
			int top=st.top();st.pop();
			if (st.empty()) ans=max(ans,1ll*i*a[top]);
			else ans=max(ans,1ll*a[top]*(i-st.top()-1));
		}
	}
	while (!st.empty()){
		int top=st.top();st.pop();
		if (st.empty()) ans=max(ans,1ll*i*a[top]);
		else ans=max(ans,1ll*a[top]*(i-st.top()-1));
	}
	i=0;
	ll res=0;
	while (i<n){
		if (st.empty() || m-a[i]>=m-a[st.top()]){
			st.push(i);
			++i;
		}else{
			int top=st.top();st.pop();
			if (st.empty()) res=max(res,1ll*i*(m-a[top]));
			else res=max(res,1ll*(m-a[top])*(i-st.top()-1));
		}
	}
	while (!st.empty()){
		int top=st.top();st.pop();
		if (st.empty()) res=max(res,1ll*i*(m-a[top]));
		else res=max(res,1ll*(m-a[top])*(i-st.top()-1));
	}
	cout << max(ans,res);
	return 0;
}
