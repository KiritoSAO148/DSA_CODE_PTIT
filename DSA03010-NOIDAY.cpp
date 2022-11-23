#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		priority_queue <int,vector<int>,greater<int>> pq;
		for (int &x : a){
			cin >> x;
			pq.push(x);
		}
		long long ans=0;
		while (pq.size()>1){
			int x=pq.top();
			pq.pop();
			int y=pq.top();
			pq.pop();
			ans+=x+y;
			pq.push(x+y);
		}
		cout << ans << endl;
	}
}
