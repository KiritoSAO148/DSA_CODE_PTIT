#include <bits/stdc++.h>
using namespace std;

int solve(long long a[], int n){
	int min=a[0], min_idx=0;
	for (int i=0; i<n; i++){
		if (min>a[i]){
			min=a[i];
			min_idx=i;
		}
	}
	return min_idx;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		long long a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		cout << solve(a,n) << endl;
	}
	return 0;
}
