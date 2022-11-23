#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	for (int b=n/7; b>=0; b--){
		int r=n-b*7;
		if (r%4==0){
			int a=r/4;
			cout << string(a,'4');
			cout << string(b,'7');
			return;
		}
	}
	cout << -1;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		solve(n);
		cout << endl;
	}
	return 0;
}
