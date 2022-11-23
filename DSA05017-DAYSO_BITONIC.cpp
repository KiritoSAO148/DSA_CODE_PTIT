#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[101], dp1[101], dp2[101];
		
		for (int i=1; i<=n; i++) cin >> a[i];
		int ans=0;
		for (int i=1; i<=n; i++){
			dp1[i]=a[i];
			for (int j=1; j<i; j++){
				if (a[j]<a[i]) dp1[i]=max(dp1[i],dp1[j]+a[i]);
			}
		}
		for (int i=n; i>=1; i--){
			dp2[i]=a[i];
			for (int j=n; j>i; j--){
				if (a[j]<a[i]) dp2[i]=max(dp2[i],dp2[j]+a[i]);
			}
		}
		for (int i=1; i<=n; i++) ans=max(ans,dp1[i]+dp2[i]-a[i]);
		cout << ans << endl;
	}
	return 0;
}
