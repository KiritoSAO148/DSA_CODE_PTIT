#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n){
	if (n >= 0 && n <= 9) return n;
	stack <int> st;
	for (int i = 9; i >= 2 && n > 1; --i){
		while (n % i == 0){
			st.push(i);
			n /= i;
		}
	}
	if (n != 1) return -1;
	ll ans = 0;
	while (!st.empty()){
		ans = ans * 10 + st.top();
		st.pop();
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}
