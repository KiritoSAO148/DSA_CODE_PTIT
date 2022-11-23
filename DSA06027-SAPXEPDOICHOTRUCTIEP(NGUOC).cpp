#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;

void solve (int a[], int n){
	vector<int>res[n];
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (a[i]>a[j]) swap(a[i],a[j]);
		}
		for (int j=0; j<n; j++){
			res[i].pb(a[j]);
		}
	}
	for (int i=n-2; i>=0; i--){
		cout << "Buoc " << i+1 << ": ";
		for (int x : res[i]) cout << x << " ";
		cout << endl;
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		solve(a,n);
	}
	return 0;
}
