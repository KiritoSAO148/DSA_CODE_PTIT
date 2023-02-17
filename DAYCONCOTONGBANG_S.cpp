#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, a[35], x[35], s, ok = INT_MAX;

void Try (int i, int sum, int pos){
	if (sum == s){
		ok = min(ok, i - 1);
		return;
	}
	for (int j = pos; j <= n; ++j){
		if (sum + a[j] <= s){
			Try(i + 1, sum + a[j], j + 1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	Try(1, 0, 1);
	if (ok == INT_MAX) cout << -1;
	else cout << ok;
	return 0;
}
