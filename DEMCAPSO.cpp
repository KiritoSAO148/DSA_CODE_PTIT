#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int m,n; cin >> m >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	stack<int>st;
	ll res=0;
	int i=0;
	while (i<n){
		if (st.empty() || a[i]>=a[st.top()]){
			st.push(i);
			++i;
		}else{
			int top = st.top();st.pop();
			if (st.empty()) res=max(res,1ll*i*a[top]);
			else res=max(res,1ll*(i-st.top()-1)*a[top]);
		}
	}
	while (!st.empty()){
		int top = st.top();st.pop();
		if (st.empty()) res=max(res,1ll*i*a[top]);
		else res=max(res,1ll*(i-st.top()-1)*a[top]);
	}
	i=0;
	ll ans=0;
	while (i<n){
		if (st.empty() || m-a[i]>=m-a[st.top()]){
			st.push(i);
			++i;
		}else{
			int top = st.top();st.pop();
			if (st.empty()) ans=max(ans,1ll*i*(m-a[top]));
			else ans=max(ans,1ll*(i-st.top()-1)*(m-a[top]));
		}
	}
	while (!st.empty()){
		int top = st.top();st.pop();
		if (st.empty()) ans=max(ans,1ll*i*(m-a[top]));
		else ans=max(ans,1ll*(i-st.top()-1)*(m-a[top]));
	}
	cout << max(ans,res);
	return 0;
}
