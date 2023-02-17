#include <bits/stdc++.h>
using namespace std;

int bs (int a[], int n, int s, int k){
	int l = 1, r = s;
	int res = -1;
	while (l <= r){
		int m = (l + r) / 2;
		int sum = 0;
		for (int i = m; i <= s; ++i) sum += a[i];
		if (sum <= k){
			res = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		int n, s, k;
		cin >> n >> s >> k;
		int a[n + 1];
		for (int i = 1; i <= n; ++i) cin >> a[i];
		cout << bs(a, n, s, k);
		cout << "\n";
	}
	return 0;
}
