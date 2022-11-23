#include<bits/stdc++.h>
using namespace std;


int solve(int sum, int n, int a[]){
	int s = 0;
	for (int i = 0; i < n; i++){
		s += a[i];
		if (s == sum - s + a[i]) return i+1;
	}
	return -1;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		cout << solve(sum, n, a) << endl;
	}
}
