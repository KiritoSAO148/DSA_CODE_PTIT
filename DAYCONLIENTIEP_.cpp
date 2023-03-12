#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cnt = 0, ans = 0, res = *max_element(a, a + n);
    for (int i = 0; i < n; ++i){
    	if (a[i] == res) ++cnt;
    	else{
    		ans = max(ans, cnt);
    		cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cnt = 0;
	cout << ans;
    return 0;
}

