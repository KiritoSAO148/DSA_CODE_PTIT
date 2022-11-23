#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

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
		ll ans=0;
		while (pq.size()>1){
			int x=pq.top();
			pq.pop();
			int y=pq.top();
			pq.pop();
			ans+=(x+y)%MOD;
			//ans%=MOD;
			pq.push((x+y)%MOD);
		}
		cout << ans%MOD << endl;
	}
	return 0;
}
