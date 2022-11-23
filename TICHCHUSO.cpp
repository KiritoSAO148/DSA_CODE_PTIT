#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(ll p){
	int n=0;
	ll a[101];
	if (p==1){
		cout << p << "\n";
		return;
	}
	if (p<10){
		cout << p+10 << "\n";
		return;
	}
	for (int i=9; i>1; i--){
		while (p%i==0){
			p/=i;
			a[n++]=i;
		}
	}
	if (p>10){
		cout << "-1\n";
		return;
	}
	for (int i=n-1; i>=0; i--){
		cout << a[i];
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		ll p; cin >> p;
		solve(p);
	}
	return 0;
}
