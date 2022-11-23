#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n+1];
		int l[n+1];
		for (int i=1; i<=n; i++) cin >> a[i];
		stack<int>st;
		for (int i=1; i<=n; i++){
			while (!st.empty() && a[i]>=a[st.top()]) st.pop();
			if (st.empty()) l[i]=0;
			else l[i]=st.top();
			st.push(i);
		}
		for (int i=1; i<=n; i++) cout << i-l[i] << ' ';
		cout << endl;
	}
	return 0;
}
