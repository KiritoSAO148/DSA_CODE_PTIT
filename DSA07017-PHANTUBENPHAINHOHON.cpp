#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		stack<int>st1;
		int r[n]={-1};
		for (int i=n-1; i>=0; i--){
			while (!st1.empty() && a[i]>=a[st1.top()]) st1.pop();
			if (st1.empty()) r[i]=-1;
			else r[i]=st1.top();
			st1.push(i);
		}
		int l[n]={-1};
		stack<int>st2;
		for (int i=n-1; i>=0; i--){
			while (!st2.empty() && a[i]<=a[st2.top()]) st2.pop();
			if (st2.empty()) l[i]=-1;
			else l[i]=st2.top();
			st2.push(i);
		}
		for (int i=0; i<n; i++){
			if (r[i]!=-1 && l[r[i]]!=-1) cout << a[l[r[i]]] << ' ';
			else cout << -1 << ' ';
		}
		cout << endl;
	}
	return 0;
}
