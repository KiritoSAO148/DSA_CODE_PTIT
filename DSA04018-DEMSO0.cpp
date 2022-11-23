#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		queue<int>q;
		for (int i=0; i<n; i++){
			cin >> a[i];
			if (a[i]==0) q.push(a[i]);
		}
		cout << q.size() << endl;
	}
	return 0;
}
