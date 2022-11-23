#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		map<int,int>mp;
		for (int i=0; i<n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		stack<int>st;
		int r[n]={-1};
		for (int i=n-1; i>=0; i--){
			while (!st.empty() && mp[a[i]]>=mp[a[st.top()]]) st.pop();
			if (st.empty()) r[i]=-1;
			else r[i]=a[st.top()];
			st.push(i);
		}
		for (int i=0; i<n; i++) cout << r[i] << ' ';
		cout << "\n";
	}
	return 0;
}
